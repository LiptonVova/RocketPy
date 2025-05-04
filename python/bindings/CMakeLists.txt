cmake_minimum_required(VERSION 3.13.3)
project(rocket_simulation)

set(ANACONDA_HOME "/home/vova_rybin/anaconda3/envs/Rocket")
set(pybind11_DIR "${ANACONDA_HOME}/lib/python3.13/site-packages/pybind11/share/cmake/pybind11")

find_package(Python REQUIRED COMPONENTS Development Interpreter)
find_package(pybind11 REQUIRED)

message(STATUS "Python found: ${Python_EXECUTABLE}")
message(STATUS "pybind11 found: ${pybind11_INCLUDE_DIR}")

set(ROOT_DIR "/home/vova_rybin/anaconda3/envs/Rocket")
find_package(ROOT REQUIRED COMPONENTS Core Graf Gpad)
message(STATUS "ROOT found: ${ROOT_INCLUDE_DIRS}")

set(COMMON_INCLUDES
    ${pybind11_INCLUDE_DIRS}
    ${Python_INCLUDE_DIRS}
    ../../cpp/simcalc/
    ../../cpp/vroot/
)

add_library(rocket_common STATIC
    ../../cpp/simcalc/calc.cpp
    ../../cpp/vroot/root.cpp
)
target_include_directories(rocket_common PRIVATE ${COMMON_INCLUDES})
target_link_libraries(rocket_common PRIVATE ROOT::Core ROOT::Graf ROOT::Gpad)

pybind11_add_module(rocket_core
    wrapper_simcalc.cpp
)
target_include_directories(rocket_core PRIVATE ${COMMON_INCLUDES})
target_link_libraries(rocket_core PRIVATE rocket_common)

pybind11_add_module(rocket_root
    wrapper_root.cpp
)
target_include_directories(rocket_root PRIVATE ${COMMON_INCLUDES})
target_link_libraries(rocket_root PRIVATE rocket_common)

set_property(TARGET rocket_core rocket_root rocket_common PROPERTY
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

install(TARGETS rocket_core rocket_root
    LIBRARY DESTINATION lib/python3.13/site-packages 
)
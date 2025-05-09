cmake_minimum_required(VERSION 3.13.3)
project(rocket_simulation)

# set(ANACONDA_HOME "/home/vova_rybin/anaconda3/envs/Rocket")
# set(pybind11_DIR "${ANACONDA_HOME}/lib/python3.13/site-packages/pybind11/share/cmake/pybind11")

find_package(Python REQUIRED COMPONENTS Development Interpreter)
find_package(pybind11 REQUIRED)

# message(STATUS "Python found: ${Python_EXECUTABLE}")
# message(STATUS "pybind11 found: ${pybind11_INCLUDE_DIR}")

pybind11_add_module(_rocketSim 
    src/wrapper.cpp 
    src/simcalc/calc.cpp
)

set_property(TARGET _rocketSim PROPERTY
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

set_target_properties(_rocketSim PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/PyRocketSim
    OUTPUT_NAME "_rocketSim"
    SUFFIX "${PYBIND11_MODULE_EXTENSION}"
)
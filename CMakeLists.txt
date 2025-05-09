cmake_minimum_required(VERSION 3.15)
project(PyRocketSim)

# Явно указываем пути к Python
set(Python3_FIND_STRATEGY LOCATION)
set(Python3_ROOT_DIR "/opt/python/cp36-cp36m")
set(Python3_EXECUTABLE "/opt/python/cp36-cp36m/bin/python")
set(Python3_INCLUDE_DIR "/opt/python/cp36-cp36m/include/python3.6m")
set(Python3_LIBRARY "/opt/python/cp36-cp36m/lib/libpython3.6m.so")

find_package(Python3 3.6 REQUIRED COMPONENTS Interpreter Development Development.Module Development.Embed)
find_package(pybind11 REQUIRED)

message(STATUS "Python3_EXECUTABLE: ${Python3_EXECUTABLE}")
message(STATUS "Python3_INCLUDE_DIRS: ${Python3_INCLUDE_DIRS}")
message(STATUS "Python3_LIBRARIES: ${Python3_LIBRARIES}")

pybind11_add_module(_rocketSim
    src/wrapper.cpp
    src/simcalc/calc.cpp
)

target_include_directories(_rocketSim PRIVATE
    ${Python3_INCLUDE_DIRS}
    ${pybind11_INCLUDE_DIRS}
)

set_target_properties(_rocketSim PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
    OUTPUT_NAME "_rocketSim"
    PREFIX ""
    SUFFIX ".so"
)
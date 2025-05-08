cmake_minimum_required(VERSION 3.13.3)
project(rocket_simulation)

set(ANACONDA_HOME "/home/vova_rybin/anaconda3/envs/Rocket")
set(pybind11_DIR "${ANACONDA_HOME}/lib/python3.13/site-packages/pybind11/share/cmake/pybind11")

find_package(Python REQUIRED COMPONENTS Development Interpreter)
find_package(pybind11 REQUIRED)

message(STATUS "Python found: ${Python_EXECUTABLE}")
message(STATUS "pybind11 found: ${pybind11_INCLUDE_DIR}")

pybind11_add_module(rocket_core 
    src/wrapper.cpp 
    src/simcalc/calc.cpp
)

set_property(TARGET rocket_core PROPERTY
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

set_target_properties(rocket_core PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/rocket
)
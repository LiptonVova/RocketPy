cmake_minimum_required(VERSION 3.13.3)
project(rocket_simulation)

add_subdirectory(pybind11)

pybind11_add_module(_rocketSim 
    src/wrapper.cpp 
    src/simcalc/calc.cpp
)
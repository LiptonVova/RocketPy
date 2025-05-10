cmake_minimum_required(VERSION 3.13.3)
project(rocket_simulation)

add_subdirectory(pybind11)
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
)
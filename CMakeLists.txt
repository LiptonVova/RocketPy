cmake_minimum_required(VERSION 3.13.3)
project(rocket_simulation)

add_subdirectory(pybind11)

pybind11_add_module(_rocketSim 
    src/wrapper.cpp 
    src/simcalc/calc.cpp
)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set_target_properties(_rocketSim PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/PyRocketSim/Release
        PREFIX ""
        SUFFIX ".so"
    )
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set_target_properties(_rocketSim PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/PyRocketSim
        PREFIX ""
        SUFFIX ".pyd"
    )
endif()
cmake_minimum_required(VERSION 3.15)
project(PyRocketSim)

# Явно указываем путь к pybind11 через переменную окружения
if(DEFINED ENV{pybind11_DIR})
    set(pybind11_DIR $ENV{pybind11_DIR})
endif()

find_package(Python REQUIRED COMPONENTS Interpreter Development)
find_package(pybind11 REQUIRED)

pybind11_add_module(_rocketSim
    src/wrapper.cpp
    src/simcalc/calc.cpp
)

target_include_directories(_rocketSim PRIVATE ${pybind11_INCLUDE_DIRS})
target_compile_features(_rocketSim PRIVATE cxx_std_17)

set_target_properties(_rocketSim PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
    OUTPUT_NAME "_rocketSim"
    PREFIX ""
    SUFFIX ".so"
)
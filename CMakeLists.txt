cmake_minimum_required(VERSION 3.16)
project(DynamicsLibrary LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON) # REQUIRED for Python modules
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/dependencies.cmake)

# =========================
# Core C++ Library
# =========================

add_library(DynamicsLibrary STATIC core/simulate.cpp)

target_sources(
    DynamicsLibrary
    PUBLIC
        FILE_SET HEADERS
            BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
            FILES
                core/simulate.hpp
                core/models/kinematic_bicycle.hpp
                core/integration/euler.hpp
)

target_link_libraries(DynamicsLibrary PUBLIC Eigen3::Eigen)

# =========================
# Python Module
# =========================

pybind11_add_module(_DynamicsLibrary
    bindings/pybind_module.cpp
    bindings/model_bindings.cpp
)

target_link_libraries(_DynamicsLibrary PRIVATE DynamicsLibrary)

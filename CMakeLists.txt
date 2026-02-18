cmake_minimum_required(VERSION 3.16)
project(DynamicsLibrary LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON) # REQUIRED for Python modules
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/dependencies.cmake)

# =========================
# Core C++ Library
# =========================

add_library(DynamicsLibrary INTERFACE)

target_include_directories(
    DynamicsLibrary
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/core
)

# =========================
# Python Module
# =========================

pybind11_add_module(_DynamicsLibrary
    bindings/pybind_module.cpp
    bindings/kinematic_bicycle_model.cpp
)

target_link_libraries(_DynamicsLibrary PRIVATE Eigen3::Eigen DynamicsLibrary)

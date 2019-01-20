cmake_minimum_required(VERSION 3.11)

project(OpenCQT)

set(OpenCQT_VERSION_MAJOR 0)
set(OpenCQT_VERSION_MINOR 1)
set(OpenCQT_VERSION "${OpenCQT_VERSION_MAJOR}.${OpenCQT_VERSION_MINOR}")

add_subdirectory(infoparse)

if(NOT RELEASE)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

configure_file(
    "${PROJECT_SOURCE_DIR}/versioning.hpp.in"
    "${PROJECT_SOURCE_DIR}/versioning.hpp"
)

set(PROJECT_SOURCES main.cpp)
set(PROJECT_HEADERS versioning.hpp)

add_executable(ocqt ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_link_libraries(ocqt infoparse)

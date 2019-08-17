cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 17)
project(OpenCQT)

set(OpenCQT_VERSION_MAJOR 0)
set(OpenCQT_VERSION_MINOR 1)
set(OpenCQT_VERSION "${OpenCQT_VERSION_MAJOR}.${OpenCQT_VERSION_MINOR}")

configure_file(
        "${PROJECT_SOURCE_DIR}/versioning.hpp.in"
        "${PROJECT_SOURCE_DIR}/versioning.hpp"
)

# Load the required libraries, local or not
include(utilities/load_libs.cmake)

set(PROJECT_SOURCES main.cpp)
set(PROJECT_HEADERS versioning.hpp parsing/Parser.cpp parsing/Parser.hpp parsing/ParserGrammar.cpp parsing/ParserGrammar.hpp)

add_executable(ocqt ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_link_libraries(ocqt cqt infoparse)
set_target_properties(ocqt PROPERTIES LINKER_LANGUAGE CXX)

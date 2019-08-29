cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
project(OpenCQT)

set(OpenCQT_VERSION_MAJOR 0)
set(OpenCQT_VERSION_MINOR 1)
set(OpenCQT_VERSION_PATCH 3)
set(OpenCQT_VERSION "${OpenCQT_VERSION_MAJOR}.${OpenCQT_VERSION_MINOR}.${OpenCQT_VERSION_PATCH}")

configure_file(
        "${CMAKE_SOURCE_DIR}/src/versioning.hpp.in"
        "${CMAKE_SOURCE_DIR}/src/versioning.hpp"
)

# Load the required libraries, local or not
include(utils/load_libs.cmake)

set(PROJECT_SOURCES src/main.cpp)
set(PROJECT_HEADERS
        src/versioning.hpp
        #        src/parsing/Parser.cpp
        #        src/parsing/Parser.hpp
        src/parsing/ParserGrammar.cpp
        src/parsing/ParserGrammar.hpp
        )

add_executable(ocqt ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_link_libraries(ocqt cqt infoparse starch)
set_target_properties(ocqt PROPERTIES LINKER_LANGUAGE CXX)

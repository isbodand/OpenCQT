cmake_minimum_required(VERSION 3.11)

project(InfoParse)

set(InfoParse_VERSION_MAJOR 0)
set(InfoParse_VERSION_MINOR 1)
set(InfoParse_VERSION "${InfoParse_VERSION_MAJOR}.${InfoParse_VERSION_MINOR}")

configure_file(
    "${PROJECT_SOURCE_DIR}/versioning.hpp.in"
    "${PROJECT_SOURCE_DIR}/versioning.hpp"
)

set(InfoParse_SOURCES 
    RawParseOption.cpp ParseOptionEmptyException.cpp
)
set(InfoParse_HEADERS versioning.hpp 
    RawParseOption.hpp ParseOptionEmptyException.hpp
)

add_library(infoparse ${InfoParse_HEADERS} ${InfoParse_SOURCES})

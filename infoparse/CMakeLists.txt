cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 17)
project(InfoParse)

set(InfoParse_VERSION_MAJOR 0)
set(InfoParse_VERSION_MINOR 1)
set(InfoParse_VERSION "${InfoParse_VERSION_MAJOR}.${InfoParse_VERSION_MINOR}")

configure_file(
        "${PROJECT_SOURCE_DIR}/versioning.hpp.in"
        "${PROJECT_SOURCE_DIR}/versioning.hpp"
)

set(InfoParse_SOURCES
        MatchResult.cpp
        ParseOptionEmptyException.cpp
        ParameterHandler.cpp
        )

set(InfoParse_HEADERS
        versioning.hpp unless.hpp
        options/ParseOption.hpp
        MatchResult.hpp
        ParseOptionEmptyException.hpp
        ParameterHandler.hpp
        )

if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else ()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif ()

add_library(infoparse ${InfoParse_HEADERS} ${InfoParse_SOURCES})
target_link_libraries(infoparse ${CONAN_LIBS})
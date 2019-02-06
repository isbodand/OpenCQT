cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 17)
project(InfoParse)

set(InfoParse_VERSION_MAJOR 0)
set(InfoParse_VERSION_MINOR 2-a)
set(InfoParse_VERSION "${InfoParse_VERSION_MAJOR}.${InfoParse_VERSION_MINOR}")

configure_file(
        "${PROJECT_SOURCE_DIR}/versioning.hpp.in"
        "${PROJECT_SOURCE_DIR}/versioning.hpp"
)

set(InfoParse_SOURCES
        utils.cpp __Option.cpp OptionsParser.cpp OptionsParser.hpp)

set(InfoParse_HEADERS
        versioning.hpp utils.hpp
        __Option.hpp __OptionHandler.hpp OptionsParser.cpp OptionsParser.hpp)

if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else ()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif ()

add_library(infoparse ${InfoParse_HEADERS} ${InfoParse_SOURCES})
target_link_libraries(infoparse ${CONAN_LIBS})
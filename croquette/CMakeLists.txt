cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 17)
project(libCroquette CXX)

set(libCroquette_VERSION_MAJOR 0)
set(libCroquette_VERSION_MINOR 1)
set(libCroquette_RELEASE_NOTE α)
set(libCroquette_VERSION "${libCroquette_VERSION_MAJOR}.${libCroquette_VERSION_MINOR}-${libCroquette_RELEASE_NOTE}")

if (NOT RELEASE)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif ()

configure_file(
        "${PROJECT_SOURCE_DIR}/versioning.hpp.in"
        "${PROJECT_SOURCE_DIR}/versioning.hpp"
)

set(libCroquette_SOURCES
        uniprint.cpp cqt.cpp
        types/Archetype.cpp
        types/Archeutils.cpp
        types/ScalarArchetype.cpp
        types/ArrayArchetype.cpp
        public_types/TrueScalarType.cpp
        public_types/CharacterScalar.cpp
        )
set(libCroquette_HEADERS
        versioning.hpp
        uniprint.hpp cqt.hpp
        types/Archetype.hpp
        types/Archeutils.hpp
        types/ScalarArchetype.hpp
        types/ArrayArchetype.hpp
        public_types/TrueScalarType.hpp
        public_types/CharacterScalar.hpp
        )

if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else ()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif ()

add_library(croquette ${libCroquette_HEADERS} ${libCroquette_SOURCES})
set_target_properties(croquette PROPERTIES LINKER_LANGUAGE CXX) # idk why need be though
target_link_libraries(croquette ${CONAN_LIBS})
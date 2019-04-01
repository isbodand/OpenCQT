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

set(libCroquette_HEADERS
        versioning.hpp
        uniprint.hpp cqt.hpp
        types/archetypes/AnyArchetype.hpp
        types/archetypes/ArchetypeUtilities.hpp
        types/archetypes/ArrayArchetype.hpp
        types/archetypes/HashArchetype.hpp
        types/archetypes/ReferenceArchetype.hpp
        types/archetypes/ScalarArchetype.hpp
        # Types used as actual values in Croquette programs
        # Archetypes may show their stinking head, but
        # they are never instatiated by themselves
        types/user_types/FlatArrayType.hpp          # Array with only scalars
        types/user_types/ComplexArrayType.hpp       # Array with everything
        types/user_types/TrueScalarType.hpp         # A Scalar number
        types/user_types/CharacterScalarType.hpp    # A Scalar character implicitly number in calc
        )

set(libCroquette_SOURCES
        uniprint.cpp cqt.cpp
        types/archetypes/AnyArchetype.cpp
        types/archetypes/ArrayArchetype.cpp
        types/archetypes/HashArchetype.cpp
        types/archetypes/ReferenceArchetype.cpp
        types/archetypes/ScalarArchetype.cpp
        types/user_types/FlatArrayType.cpp
        types/user_types/ComplexArrayType.cpp
        types/user_types/TrueScalarType.cpp
        types/user_types/CharacterScalarType.cpp
        types/archetypes/ArchetypeUtilities.cpp)

add_library(croquette STATIC ${libCroquette_HEADERS} ${libCroquette_SOURCES})
add_library(cqt SHARED ${libCroquette_HEADERS} ${libCroquette_SOURCES})
set_target_properties(croquette PROPERTIES LINKER_LANGUAGE CXX) # idk why need be though
set_target_properties(cqt PROPERTIES LINKER_LANGUAGE CXX) # idk why need be though
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
project(libCroquette CXX)

set(libCroquette_VERSION_MAJOR 0)
set(libCroquette_VERSION_MINOR 1)
set(libCroquette_RELEASE_NOTE β)
set(libCroquette_VERSION "${libCroquette_VERSION_MAJOR}.${libCroquette_VERSION_MINOR}-${libCroquette_RELEASE_NOTE}")

if (NOT RELEASE)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif ()

configure_file(
        "${PROJECT_SOURCE_DIR}/src/versioning.hpp.in"
        "${PROJECT_SOURCE_DIR}/src/versioning.hpp"
)

set(libCroquette_HEADERS
        src/versioning.hpp
        src/uniprint.hpp src/cqt.hpp
        src/types/archetypes/AnyArchetype.hpp
        src/types/archetypes/ArchetypeUtilities.hpp
        src/types/archetypes/ArrayArchetype.hpp
        src/types/archetypes/HashArchetype.hpp
        src/types/archetypes/ReferenceArchetype.hpp
        src/types/archetypes/ScalarArchetype.hpp
        # Types used as actual values in Croquette programs
        # Archetypes may show their stinking head, but
        # they are never instatiated by themselves
        src/types/user_types/FlatArrayType.hpp          # archArray with only scalars
        src/types/user_types/ComplexArrayType.hpp       # archArray with everything
        src/types/user_types/TrueScalarType.hpp         # A archScalar number
        src/types/user_types/CharacterScalarType.hpp    # A archScalar character implicitly number in calc
        src/types/user_types/HashmapType.hpp            # A archHash
        src/types/user_types/OrderedMapType.hpp         # A Map
        # Casts between the concrete Types of the same Archetype
        src/types/user_types/casts/ScalarCast.hpp
        src/types/user_types/casts/ArrayCast.hpp
        # Misc.
        src/types/user_types/EqualityOperators.hpp
        )

set(libCroquette_SOURCES
        src/uniprint.cpp src/cqt.cpp
        src/types/archetypes/AnyArchetype.cpp
        src/types/archetypes/ArrayArchetype.cpp
        src/types/archetypes/HashArchetype.cpp
        src/types/archetypes/ReferenceArchetype.cpp
        src/types/archetypes/ScalarArchetype.cpp
        src/types/archetypes/ArchetypeUtilities.cpp

        src/types/user_types/FlatArrayType.cpp
        src/types/user_types/ComplexArrayType.cpp
        src/types/user_types/TrueScalarType.cpp
        src/types/user_types/CharacterScalarType.cpp
        src/types/user_types/HashmapType.cpp
        src/types/user_types/OrderedMapType.cpp

        src/types/user_types/casts/ScalarCast.cpp
        src/types/user_types/casts/ArrayCast.cpp

        src/types/user_types/EqualityOperators.cpp
        )

add_library(cqt STATIC ${libCroquette_HEADERS} ${libCroquette_SOURCES})
add_library(croquette SHARED ${libCroquette_HEADERS} ${libCroquette_SOURCES})
set_target_properties(croquette PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(cqt PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(test)

set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header files")
if (WIN32 AND NOT CYGWIN)
    set(DEF_INSTALL_CMAKE_DIR CMake)
else ()
    set(DEF_INSTALL_CMAKE_DIR lib/CMake/LibCroquette)
endif ()
set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH "Installation directory for CMake files")

foreach (header ${LibCroquette_HEADERS})
    # Dynamic library headers
    get_target_property(pub croquette PUBLIC_HEADER)
    if ("${pub}" STREQUAL "pub-NOTFOUND")
        set_target_properties(croquette PROPERTIES PUBLIC_HEADER "${header}")
    else ()
        set_target_properties(croquette PROPERTIES PUBLIC_HEADER "${header};${pub}")
    endif ()
    # Static library headers
    get_target_property(pub cqt PUBLIC_HEADER)
    if ("${pub}" STREQUAL "pub-NOTFOUND")
        set_target_properties(cqt PROPERTIES PUBLIC_HEADER "${header}")
    else ()
        set_target_properties(cqt PROPERTIES PUBLIC_HEADER "${header};${pub}")
    endif ()
endforeach ()

install(TARGETS croquette EXPORT LibCroquetteConfig
        RUNTIME DESTINATION ${INSTALL_BIN_DIR}
        LIBRARY DESTINATION ${INSTALL_LIB_DIR}
        PUBLIC_HEADER DESTINATION ${INSTALL_INCLUDE_DIR}
        )
install(TARGETS cqt EXPORT LibCroquetteConfig
        RUNTIME DESTINATION ${INSTALL_BIN_DIR}
        ARCHIVE DESTINATION ${INSTALL_LIB_DIR}/static
        )
install(EXPORT LibCroquetteConfig DESTINATION ${INSTALL_CMAKE_DIR})

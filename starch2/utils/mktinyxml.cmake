message(STATUS "Downloading External Library 'TinyXML2'")
set(TINY_XML_DIR "${LibStarch_EXTERNAL_LIBS_DIR}/tinyxml2")
if (NOT EXISTS "${TINY_XML_DIR}")
    if (NOT EXISTS "${LibStarch_EXTERNAL_LIBS_DIR}")
        file(MAKE_DIRECTORY "${LibStarch_EXTERNAL_LIBS_DIR}")
    endif ()
    find_program(GIT_EXEC git)

    if (WIN32)
        execute_process(
                COMMAND cmd /c "${GIT_EXEC}" clone https://github.com/leethomason/tinyxml2.git ${TINY_XML_DIR}
                WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        )
    else ()
        execute_process(
                COMMAND "${GIT_EXEC}" clone https://github.com/leethomason/tinyxml2.git ${TINY_XML_DIR}
                WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        )
    endif ()
    message(STATUS "Downloading External Library 'TinyXML2' - Done")
else ()
    message(STATUS "Downloading External Library 'TinyXML2' - Cached")
endif ()

message(STATUS "Registering External Library 'TinyXML2'")
add_subdirectory(${TINY_XML_DIR})

message(STATUS "- Installing header files for project")
message(STATUS "-- Creating include directory")
if (NOT EXISTS "${LibStarch_EXTERNAL_LIBS_INC}")
    file(MAKE_DIRECTORY "${LibStarch_EXTERNAL_LIBS_INC}")
    message(STATUS "-- Creating include directory - Done")
else ()
    message(STATUS "-- Creating include directory - Cached")
endif ()
message(STATUS "-- Collecting header files")
file(GLOB TINY_XML_HEADER_FILES "${TINY_XML_DIR}/*.h")
message(STATUS "-- Collecting header files - Done")
file(COPY ${TINY_XML_HEADER_FILES} DESTINATION "${LibStarch_EXTERNAL_LIBS_INC}/tinyxml2")
message(STATUS "- Installing header files for project - Done")

message(STATUS "Registering External Library 'TinyXML2' - Done")

message(STATUS "Downloading External Library 'InfoParse'")
set(INFOPARSE_DIR "${OpenCQT_EXTERNAL_LIBS_DIR}/infoparse")
if (NOT EXISTS "${INFOPARSE_DIR}")
    if (NOT EXISTS "${OpenCQT_EXTERNAL_LIBS_DIR}")
        file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/${OpenCQT_EXTERNAL_LIBS_DIR}")
    endif ()
    find_program(GIT_EXEC git)

    if (WIN32)
        execute_process(
                COMMAND cmd /c "${GIT_EXEC}" clone https://github.com/isbodand/infoparse.git ${INFOPARSE_DIR}
                WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        )
    else ()
        execute_process(
                COMMAND "${GIT_EXEC}" clone https://github.com/isbodand/infoparse.git ${INFOPARSE_DIR}
                WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        )
    endif ()
    message(STATUS "Downloading External Library 'InfoParse' - Done")
else ()
    message(STATUS "Downloading External Library 'InfoParse' - Cached")
endif ()

message(STATUS "Registering External Library 'InfoParse'")
add_subdirectory(${INFOPARSE_DIR})

message(STATUS "- Installing files for project")
message(STATUS "-- Creating include directory")
if (NOT EXISTS "${CMAKE_SOURCE_DIR}/${OpenCQT_EXTERNAL_LIBS_INC}")
    file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/${OpenCQT_EXTERNAL_LIBS_INC}")
    message(STATUS "-- Creating include directory - Done")
else ()
    message(STATUS "-- Creating include directory - Cached")
endif ()
message(STATUS "-- Collecting files")
file(GLOB INFO_PARSE_HEADER_FILES "${INFOPARSE_DIR}/src/*.hpp")
message(STATUS "-- Collecting files - Done")
file(COPY ${INFO_PARSE_HEADER_FILES} DESTINATION "${CMAKE_SOURCE_DIR}/${OpenCQT_EXTERNAL_LIBS_INC}/infoparse")
message(STATUS "- Installing files for project - Done")

message(STATUS "Registering External Library 'InfoParse' - Done")

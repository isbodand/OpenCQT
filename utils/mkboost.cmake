message(STATUS "Searching For External Library 'Boost'")

find_package(Boost)
if (NOT Boost_FOUND)
    # Shitstorm
    message(STATUS "Searching For External Library 'Boost' - Failure")
    message(STATUS "Getting External Library 'Boost'")

    set(CQT_BOOST_VERSION 71)
    set(LIB_DIR "${CMAKE_SOURCE_DIR}/${OpenCQT_EXTERNAL_LIBS_DIR}")

    # Download archive if not existing
    if ((NOT EXISTS "${LIB_DIR}/boost_1_${CQT_BOOST_VERSION}_0.tar.gz")
            AND (NOT EXISTS "${LIB_DIR}/boost_1_${CQT_BOOST_VERSION}_0"))
        message(STATUS "- Downloading archive")
        file(DOWNLOAD
                "https://dl.bintray.com/boostorg/release/1.${CQT_BOOST_VERSION}.0/source/boost_1_${CQT_BOOST_VERSION}_0.tar.gz"
                "${LIB_DIR}/boost_1_${CQT_BOOST_VERSION}_0.tar.gz"
                EXPECTED_HASH SHA256=96b34f7468f26a141f6020efb813f1a2f3dfb9797ecf76a7d7cbd843cc95f5bd
                )
        message(STATUS "- Downloading archive - Done")
    else ()
        message(STATUS "- Downloading archive - Cached")
    endif ()

    # Extact archive if not already done
    if ((EXISTS "${LIB_DIR}/boost_1_${CQT_BOOST_VERSION}_0.tar.gz")
            AND (NOT EXISTS "${LIB_DIR}/boost_1_${CQT_BOOST_VERSION}_0"))
        message(STATUS "- Extracting archive")
        if (WIN32)
            execute_process(
                    COMMAND cmd /c "${CMAKE_COMMAND}" -E tar xzf "boost_1_${CQT_BOOST_VERSION}_0.tar.gz"
                    WORKING_DIRECTORY "${LIB_DIR}"
            )
        else ()
            execute_process(
                    COMMAND "${CMAKE_COMMAND}" -E tar xzf "boost_1_${CQT_BOOST_VERSION}_0.tar.gz"
                    WORKING_DIRECTORY "${LIB_DIR}"
            )
        endif ()
        message(STATUS "- Extracting archive - Done")
    else ()
        message(STATUS "- Extracting archive - Cached")
    endif ()

    # Delete archive if existing
    if (EXISTS "${LIB_DIR}/boost_1_${CQT_BOOST_VERSION}_0.tar.gz")
        message(STATUS "- Deleting archive")
        file(REMOVE "${LIB_DIR}/boost_1_${CQT_BOOST_VERSION}_0.tar.gz")
        message(STATUS "- Deleting archive - Done")
    endif ()
    message(STATUS "Getting External Library 'Boost' - Done")


    # Registering
    message(STATUS "Registering External Library 'Boost'")

    message(STATUS "- Installing files for project")
    message(STATUS "-- Creating include directory")
    if (NOT EXISTS "${CMAKE_SOURCE_DIR}/${OpenCQT_EXTERNAL_LIBS_INC}")
        file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/${OpenCQT_EXTERNAL_LIBS_INC}")
        message(STATUS "-- Creating include directory - Done")
    else ()
        message(STATUS "-- Creating include directory - Cached")
    endif ()

    message(STATUS "-- Collecting files")
    set(CQT_BOOST_DIR "boost_1_${CQT_BOOST_VERSION}_0")
    message(STATUS "-- Collecting files - Done")

    message(STATUS "-- Copying files")
    if (WIN32)
        execute_process(
                COMMAND cmd /c "${CMAKE_COMMAND}" -E copy_directory "${CQT_BOOST_DIR}/boost" "${OpenCQT_EXTERNAL_LIBS_INC}/boost"
                WORKING_DIRECTORY "${LIB_DIR}"
        )
    else ()
        execute_process(
                COMMAND "${CMAKE_COMMAND}" -E copy_directory "${CQT_BOOST_DIR}/boost" "${OpenCQT_EXTERNAL_LIBS_INC}/boost"
                WORKING_DIRECTORY "${LIB_DIR}"
        )
    endif ()
    message(STATUS "-- Copying files - Done")

    message(STATUS "- Installing files for project - Done")

    message(STATUS "Registering External Library 'Boost' - Done")

else ()
    message(STATUS "Searching For External Library 'Boost' - Success")
endif ()

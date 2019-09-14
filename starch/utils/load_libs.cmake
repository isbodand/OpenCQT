message(STATUS "Loading Libraries")

# Libary loading options
set(LibStarch_EXTERNAL_LIBS_DIR "${PROJECT_SOURCE_DIR}/libs")
set(LibStarch_EXTERNAL_LIBS_INC "${LibStarch_EXTERNAL_LIBS_DIR}/include")

# TinyXML 2
include(utils/mktinyxml.cmake)
include_directories(${CMAKE_SOURCE_DIR}/libs/include)

# Boost
find_package(Boost)

if (Boost_FOUND)
    set(CQT_BOOST_MATH_FOUND 1)
else ()
    set(CQT_BOOST_MATH_FOUND 0)
endif ()

message(STATUS "Register external library headers")
include_directories(${PROJECT_SOURCE_DIR}/${LibStarch_EXTERNAL_LIBS_INC})
message(STATUS "Register external library headers - Done")

message(STATUS "Loading Libraries - Done")

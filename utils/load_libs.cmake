message(STATUS "Loading Libraries")

# Libary loading options
set(OpenCQT_EXTERNAL_LIBS_DIR libs)
set(OpenCQT_EXTERNAL_LIBS_INC "${OpenCQT_EXTERNAL_LIBS_DIR}/include")

# Boost
include(utils/mkboost.cmake)
# InfoParse
include(utils/mkip.cmake)
# Croquette STD
include(utils/mkstd.cmake)
# LibStarch
include(utils/mkstarch.cmake)

message(STATUS "Register external library headers")
include_directories(${CMAKE_SOURCE_DIR}/${OpenCQT_EXTERNAL_LIBS_INC})
message(STATUS "Register external library headers - Done")

message(STATUS "Loading Libraries - Done")

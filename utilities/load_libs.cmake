message(STATUS "Loading Libraries")

# Libary loading options
set(OpenCQT_EXTERNAL_LIBS_DIR libs)
set(OpenCQT_EXTERNAL_LIBS_INC "${OpenCQT_EXTERNAL_LIBS_DIR}/include")

# InfoParse
include(utilities/mkip.cmake)
# Croquette STD
message(STATUS "Registering Library 'CroquetteSTD'")
add_subdirectory(croquette)
message(STATUS "Registering Library 'CroquetteSTD' - Done")
# LibStarch
message(STATUS "Registering Library 'LibStarch'")
add_subdirectory(starch)
message(STATUS "Registering Library 'LibStarch' - Done")

message(STATUS "Register external library headers")
include_directories(${CMAKE_SOURCE_DIR}/${OpenCQT_EXTERNAL_LIBS_INC})
message(STATUS "Register external library headers - Done")

message(STATUS "Loading Libraries - Done")

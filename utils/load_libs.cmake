message(STATUS "Loading Libraries")

set(CDepend_FILE "${CMAKE_SOURCE_DIR}/utils/InfoCDepend.cmake")

file(DOWNLOAD
        https://raw.githubusercontent.com/isbodand/InfoCDepend/master/InfoCDepend.cmake
        "${CDepend_FILE}"
        )

include("${CDepend_FILE}")

# Boost
include(utils/mkboost.cmake) # Todo make InfoCDepend able to install Boost

# InfoParse
GetDependency(InfoParse "https://github.com/isbodand/infoparse.git")

# Croquette STD
message(STATUS "Registering Library 'CroquetteSTD'")
add_subdirectory(croquette)
message(STATUS "Registering Library 'CroquetteSTD' - Done")

# LibStarch
#GetDependency(LibStarch2 "https://github.com/isbodand/LibStarch2.git")
add_subdirectory(starch)

include_directories(libs/include)
message(STATUS "Loading Libraries - Done")

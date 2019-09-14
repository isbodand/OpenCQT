file(DOWNLOAD
        https://raw.githubusercontent.com/isbodand/InfoCDepend/master/InfoCDepend.cmake
        "${CDepend_FILE}"
        )

include("${CDepend_FILE}")

# TinyXML 2
GetDependency(TinyXML2 https://github.com/leethomason/tinyxml2.git)

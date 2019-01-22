//defines macros for program version
#define OpenCQT_MAJOR 0
#define OpenCQT_MINOR 1
#define OpenCQT_VERSION "0.1"

#include <string>

namespace OpenCqt {
    static const std::string getVersion() {
        return OpenCQT_VERSION;
    }
}

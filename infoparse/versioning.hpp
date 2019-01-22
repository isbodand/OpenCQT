#define InfoParse_MAJOR 0
#define InfoParse_MINOR 1
#define InfoParse_VERSION "0.1"

#include <string>
namespace InfoParse {
    static const std::string getVersion() {
        return InfoParse_VERSION;
    }
}

#define InfoParse_MAJOR 0
#define InfoParse_MINOR 2-a
#define InfoParse_VERSION "0.2-a"

#include <string>
namespace InfoParse {
    static const std::string getVersion() {
        return InfoParse_VERSION;
    }
}

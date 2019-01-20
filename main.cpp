#include <iostream>

#include "infoparse/versioning.hpp"
#include "versioning.hpp"

int main() {
    std::cout << "InfoSoft Croquette implementation" << std::endl
              << "OpenCQT version " << OpenCqt::getVersion() << std::endl
              << "InfoParse version " << InfoParse::getVersion() << std::endl;

    return 0;
}

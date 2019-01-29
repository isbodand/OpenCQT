#include <iostream>
#include <sstream>

#include "rang.hpp"
#include "infoparse/ParameterHandler.hpp"

namespace ip = InfoParse;

int main(int argc, char** argv) {
    std::string monolithArgs = ip::makeMonolithArgs(argc, argv);

    ip::ParameterHandler<std::string> stringHandler;
    //    stringHandler.addParameter(ip::ParseOption<std::string>("obstruct"));
    //    stringHandler.addParameter(ip::ParseOption<std::string>("slurp"));
    stringHandler.addParameter(ip::ParseOption<std::string>("polymerization", true));

    ip::ParameterHandler<bool> flagHandler;
    flagHandler.addParameter(ip::ParseOption<bool>("alpha"));
    flagHandler.addParameter(ip::ParseOption<bool>("beta"));
    flagHandler.addParameter(ip::ParseOption<bool>("gamma"));

    auto parsed = stringHandler.parse(monolithArgs);
    for (const auto& item : *parsed.first) {
        std::cout << item << std::endl;
    }
    auto flags = flagHandler.parse(monolithArgs);
    for (const auto& item : flags.second) {
        std::cout << item.first << " -> " << item.second << std::endl;
    }
    return 0;
}


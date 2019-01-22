#include <iostream>
#include <sstream>
#include <string>

#include "rang.hpp"
#include "infoparse/ParameterHandler.hpp"
#include "infoparse/options/ParseOption.hpp"
#include "infoparse/versioning.hpp"
#include "versioning.hpp"

namespace ip = InfoParse;

std::string makeMonolithArgs(int argc, char** argv);

int main(int argc, char** argv) {
    std::string monolithArgs = makeMonolithArgs(argc, argv);

    ip::ParameterHandler<std::string> stringHandler;
    stringHandler.addParameter(ip::ParseOption<std::string>("alpha"));
    stringHandler.addParameter(ip::ParseOption<std::string>("beta"));
    stringHandler.addParameter(ip::ParseOption<std::string>("gamma", true));

    auto parsed = stringHandler.parse(monolithArgs);
    for (const auto& item : *parsed.first) {
        std::cout << item << std::endl;
    }
    for (const auto& item : parsed.second) {
        std::cout << item.first << " -> " << item.second << std::endl;
    }
    return 0;
}

std::string makeMonolithArgs(int argc, char** argv) {
    std::ostringstream retStream;
    retStream << " ";
    for (int i = 1; i < argc; ++i) {
        retStream << argv[i] << " ";
    }
    return retStream.str();
}

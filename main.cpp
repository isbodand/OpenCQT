#include <iostream>
#include <sstream>
#include <vector>

#include "infoparse/ParameterHandler.hpp"
#include "infoparse/TypeInferingParameterHandler.hpp"
#include "infoparse/options/ValueOption.hpp"
#include "infoparse/options/FlagOption.hpp"

namespace ip = InfoParse;

int main(int argc, char** argv) {
    std::string monolithArgs = ip::makeMonolithArgs(argc, argv);

    ip::OptionParser parser;
    parser.addOption(ip::ValueOption<std::string>("recipe"));
    parser.addOption(ip::FlagOption("bake-pie"));
    parser.addOption(ip::ValueOption<int>("amount"));

    return 0;
}


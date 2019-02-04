//
// Created by bodand on 2019-01-23.
//

#include <string>
#include <sstream>

#include "utils.hpp"

namespace InfoParse {
    std::string makeMonolithArgs(int argc, char** argv) {
        std::ostringstream retStream;
        retStream << " ";
        for (int i = 1; i < argc; ++i) {
            retStream << argv[i] << " ";
        }
        return retStream.str();
    }
}
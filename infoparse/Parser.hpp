//
// Created by bodand on 2019-01-20.
//

#pragma once

#include <list>
#include "options/ParseOption.hpp"

namespace InfoParse {
    class Parser {
        std::list<ParseOption<std::string>> parameters;
    };
}


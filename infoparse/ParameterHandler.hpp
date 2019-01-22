//
// Created by bodand on 2019-01-20.
//

#pragma once

#include <list>
#include "options/ParseOption.hpp"

namespace InfoParse {
    template<class T>
    class Parser {
        // I have now realized it was utterly useless
        // to make ParseOption type-parameterized
        std::list<ParseOption<T>> parameters;

    public:
        Parser() = default;

        virtual ~Parser() = default;

        void addParameter(ParseOption<T> parseOption);
    };

    template<class T>
    void Parser<T>::addParameter(ParseOption<T> parseOption) {
        parameters.push_back(parseOption);
    }
}


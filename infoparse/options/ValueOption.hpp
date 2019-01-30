//
// Created by bodand on 2019-01-30.
//

#pragma once

#include "ParseOption.hpp"

namespace InfoParse {
    template<class T>
    class ValueOption : public ParseOption<T> {
    public:
        explicit ValueOption(const std::string& option);
        ValueOption(char shortOpt, const std::string& longOpt);
    };

    template<class T>
    ValueOption<T>::ValueOption(const std::string& option) :
            ParseOption<T>(option, true) {}

    template<class T>
    ValueOption<T>::ValueOption(char shortOpt, const std::string& longOpt) :
            ParseOption<T>(shortOpt, longOpt, true) {}
}

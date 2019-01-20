#pragma once

#include <string>

#include "ParseOptionEmptyException.hpp"

template <class T>
class RawParseOption {
    std::string shortOption;
    char longOption;
    bool takesValue;
    T* value = nullptr;

protected:
    RawParseOption(std::string option) :
        longOption(option),
        shortOption(option[0]),
        takesValue(false) {
    }

    RawParseOption(char shortOpt, std::string longOpt) :
        shortOption(shortOpt), 
        longOption(longOpt),
        takesValue(false) {
    }

    RawParseOption(char shortOpt, std::string longOpt, bool takesValue) :
        shortOption(shortOpt),
        longOption(longOpt),
        takesValue(false) {
    }

public:
    /** 
     * Returns current value of the ParseOption
     * throws ParseOptionEmptyException if empty
     */
    T getValue() {
        if (value == nullptr)
            throw ParseOptionEmptyException(takesValue);
        return *value;
    }
};


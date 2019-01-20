#pragma once

#include <exception>
#include <sstream>

class ParseOptionEmptyException : std::exception {
    bool shouldStore;

    ParseOptionEmptyException(bool should) : 
        shouldStore(should) {
    }

    const char* what() const noexcept override; 
};

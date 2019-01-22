#pragma once

#include <exception>
#include <sstream>

namespace InfoParse {

    class ParseOptionEmptyException : std::exception {
        bool shouldStore;

    public:
        explicit ParseOptionEmptyException(bool should) :
                shouldStore(should) {
        }

        const char* what() const noexcept override;
    };
}
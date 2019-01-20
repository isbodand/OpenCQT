#include <sstream>

#include "ParseOptionEmptyException.hpp"

const char* ParseOptionEmptyException::what() const {
    std::stringstream ss;
    ss << "ParseOption was requested to give its value but it was empty"
        << (shouldStore ? "" : "and it shouldn't do in the first place")
        << std::endl;
    return ss.str().c_str();
}

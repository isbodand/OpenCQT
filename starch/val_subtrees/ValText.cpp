#include <utility>

//
// Created by bodand on 2019-06-20.
//

#include "ValText.hpp"

const std::string& LibStarch::ValText::getValue() const {
    return value;
}

LibStarch::ValText::ValText(std::string value)
        : value(std::move(value)) {}

LibStarch::ValText::ValText(const char* value)
        : value(std::string(value)) {}

double LibStarch::ValText::eval() const {
    return std::atof(getValue().c_str());
}

void LibStarch::ValText::asString(std::ostream& os) const {
    os << "[ValText \"" << value << "\"]";
}

void LibStarch::ValText::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

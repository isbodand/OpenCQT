//
// Created by bodand on 2019-06-20.
//

#include <iostream>
#include "ValNumber.hpp"

LibStarch::ValNumber::ValNumber(double value)
        : value(value) {}

double LibStarch::ValNumber::getValue() const {
    return value;
}

double LibStarch::ValNumber::eval() const {
    return getValue();
}


void LibStarch::ValNumber::asString(std::ostream& os) const {
    os << "[ValNumber " << value << "]";
}

void LibStarch::ValNumber::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

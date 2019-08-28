//
// Created by bodand on 2019-07-08.
//

#include "LessOrEqualExpression.hpp"

void LibStarch::LessOrEqualExpression::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

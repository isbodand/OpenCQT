//
// Created by bodand on 2019-07-08.
//

#include "GreaterOrEqualExpression.hpp"

void LibStarch::GreaterOrEqualExpression::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}
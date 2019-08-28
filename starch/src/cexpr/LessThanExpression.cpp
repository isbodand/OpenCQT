//
// Created by bodand on 2019-07-08.
//

#include "LessThanExpression.hpp"

void LibStarch::LessThanExpression::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

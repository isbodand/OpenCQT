//
// Created by bodand on 2019-07-08.
//

#include "TernaryExpression.hpp"

void LibStarch::TernaryExpression::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

//
// Created by bodand on 2019-07-08.
//

#include "ValueExpression.hpp"

void LibStarch::ValueExpression::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

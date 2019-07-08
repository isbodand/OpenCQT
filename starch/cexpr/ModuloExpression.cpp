//
// Created by bodand on 2019-07-08.
//

#include "ModuloExpression.hpp"

void LibStarch::ModuloExpression::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

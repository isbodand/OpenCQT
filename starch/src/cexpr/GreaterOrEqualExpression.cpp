//
// Created by bodand on 2019-07-08.
//

#include "GreaterOrEqualExpression.hpp"

void LibStarch::GreaterOrEqualExpression::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

LibStarch::Utils::ExprType LibStarch::GreaterOrEqualExpression::getType() const {
    return Utils::Impl::exprGreaterOrEqual;
}

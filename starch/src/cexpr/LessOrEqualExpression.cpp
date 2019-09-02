//
// Created by bodand on 2019-07-08.
//

#include "LessOrEqualExpression.hpp"

void LibStarch::LessOrEqualExpression::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

LibStarch::Utils::ExprType LibStarch::LessOrEqualExpression::getType() const {
    return Utils::Impl::exprLessOrEqual;
}

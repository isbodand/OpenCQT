//
// Created by bodand on 2019-07-08.
//

#include "GreaterThanExpression.hpp"

void LibStarch::GreaterThanExpression::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

LibStarch::Utils::ExprType LibStarch::GreaterThanExpression::getType() const {
    return Utils::Impl::exprGreaterThan;
}

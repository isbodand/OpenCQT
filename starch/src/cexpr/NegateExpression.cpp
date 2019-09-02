//
// Created by bodand on 2019-07-08.
//

#include "NegateExpression.hpp"

void LibStarch::NegateExpression::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

LibStarch::Utils::ExprType LibStarch::NegateExpression::getType() const {
    return Utils::Impl::exprNegate;
}

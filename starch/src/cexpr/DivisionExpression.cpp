//
// Created by bodand on 2019-07-08.
//

#include "DivisionExpression.hpp"

void LibStarch::DivisionExpression::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

LibStarch::Utils::ExprType LibStarch::DivisionExpression::getType() const {
    return Utils::Impl::exprDivision;
}

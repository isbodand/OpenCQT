//
// Created by bodand on 2019-07-08.
//

#include "ValueExpression.hpp"

void LibStarch::ValueExpression::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

LibStarch::Utils::ExprType LibStarch::ValueExpression::getType() const {
    return Utils::Impl::exprValue;
}

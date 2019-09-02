//
// Created by bodand on 2019-07-08.
//

#include "EqualityExpression.hpp"

void LibStarch::EqualityExpression::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

LibStarch::Utils::ExprType LibStarch::EqualityExpression::getType() const {
    return Utils::Impl::exprEquality;
}

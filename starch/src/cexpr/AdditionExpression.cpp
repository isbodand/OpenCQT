//
// Created by bodand on 2019-07-07.
//

#include "AdditionExpression.hpp"

void LibStarch::AdditionExpression::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

LibStarch::Utils::ExprType LibStarch::AdditionExpression::getType() const {
    return Utils::Impl::exprAddition;
}



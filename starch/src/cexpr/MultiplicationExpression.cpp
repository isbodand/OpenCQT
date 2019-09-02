//
// Created by bodand on 2019-07-08.
//

#include "MultiplicationExpression.hpp"

void LibStarch::MultiplicationExpression::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

LibStarch::Utils::ExprType LibStarch::MultiplicationExpression::getType() const {
    return Utils::Impl::exprMultiplication;
}

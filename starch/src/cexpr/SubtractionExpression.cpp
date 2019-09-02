//
// Created by bodand on 2019-07-08.
//

#include "SubtractionExpression.hpp"

void LibStarch::SubtractionExpression::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

LibStarch::Utils::ExprType LibStarch::SubtractionExpression::getType() const {
    return Utils::Impl::exprSubtraction;
}

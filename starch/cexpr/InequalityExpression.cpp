//
// Created by bodand on 2019-07-08.
//

#include "InequalityExpression.hpp"

void LibStarch::InequalityExpression::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

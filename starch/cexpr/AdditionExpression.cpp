//
// Created by bodand on 2019-07-07.
//

#include "AdditionExpression.hpp"
#include "impl/AdditionExpressionImpl.hpp"

template<class L, class R>
LibStarch::Ptr<LibStarch::AdditionExpression> LibStarch::AdditionExpression::construct(L lhs, R rhs) {
    return mkPtr<AdditionExpressionImpl<L, R>>(lhs, rhs);
}

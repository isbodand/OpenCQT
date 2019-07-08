//
// Created by bodand on 2019-06-29.
//

#include "ValExpr.hpp"

double LibStarch::ValExpr::eval() const {
    return expr->eval();
}

void LibStarch::ValExpr::asString(std::ostream& os) const {
    os << "[ValExpr(" << expr->eval() << "): "
       << *expr
       << "]";
}

void LibStarch::ValExpr::accept(Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

const LibStarch::Ptr<LibStarch::CExpression>& LibStarch::ValExpr::getExpr() const {
    return expr;
}

LibStarch::Utils::ExprType LibStarch::ValExpr::getTyp() const {
    return typ;
}


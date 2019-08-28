//
// Created by bodand on 2019-07-01.
//

#include "AstInnerCode.hpp"

std::vector<LibStarch::Ptr<LibStarch::ASTCodePart>>& LibStarch::ASTInnerCode::getParts() {
    return parts;
}

const std::vector<LibStarch::Ptr<LibStarch::ASTCodePart>>& LibStarch::ASTInnerCode::getParts() const {
    return parts;
}

void LibStarch::ASTInnerCode::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

LibStarch::ASTInnerCode::ASTInnerCode(std::initializer_list<Ptr<ASTCodePart>> parts)
     : parts(parts) {}

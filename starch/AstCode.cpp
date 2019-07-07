#include <utility>

//
// Created by bodand on 2019-07-01.
//

#include "AstCode.hpp"

void LibStarch::ASTCode::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

std::vector<LibStarch::Ptr<LibStarch::ASTExtendedCodePart>>& LibStarch::ASTCode::getParts() {
    return parts;
}

LibStarch::ASTCode::ASTCode(std::vector<LibStarch::Ptr<LibStarch::ASTExtendedCodePart>> parts)
        : parts(std::move(parts)) {}

#include <utility>

//
// Created by bodand on 2019-07-01.
//

#include "AstRoot.hpp"

void LibStarch::ASTRoot::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

LibStarch::ASTCode& LibStarch::ASTRoot::getCode() {
    return code;
}

LibStarch::ASTRoot::ASTRoot(LibStarch::ASTCode code)
        : code(std::move(code)) {}

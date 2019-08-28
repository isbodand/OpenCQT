//
// Created by bodand on 2019-08-24.
//

#include "AstSubDefinition.hpp"

#include <utility>

int LibStarch::ASTSubDefinition::getType() const {
    return 1;
}

void LibStarch::ASTSubDefinition::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

LibStarch::ASTSubDefinition::ASTSubDefinition(const LibStarch::ValID& name, LibStarch::Utils::ASTSubParams params,
                                              LibStarch::ASTCode code)
     : ASTDefinition(name), code(std::move(code)), params(std::move(params)) {}

const LibStarch::ASTCode& LibStarch::ASTSubDefinition::getCode() const {
    return code;
}

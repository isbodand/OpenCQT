//
// Created by bodand on 2019-08-24.
//

#include "AstDefinition.hpp"

#include <utility>

const LibStarch::ValID& LibStarch::ASTDefinition::getName() const {
    return name;
}

LibStarch::ASTDefinition::ASTDefinition(LibStarch::ValID name)
     : name(std::move(name)) {}

//
// Created by bodand on 2019-07-01.
//

#include "AstWhileLoop.hpp"

LibStarch::ASTWhileLoop::ASTWhileLoop(const LibStarch::CondNode& cond,
                                      const LibStarch::ASTInnerCode& code)
        : ASTLoop(cond, code) {}

void LibStarch::ASTWhileLoop::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

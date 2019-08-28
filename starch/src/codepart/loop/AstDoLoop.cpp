//
// Created by bodand on 2019-07-01.
//

#include "AstDoLoop.hpp"

LibStarch::ASTDoLoop::ASTDoLoop(const LibStarch::CondNode& cond,
                                const LibStarch::ASTInnerCode& code)
        : ASTLoop(cond, code) {}

void LibStarch::ASTDoLoop::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

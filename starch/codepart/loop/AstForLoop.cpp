//
// Created by bodand on 2019-07-01.
//

#include "AstForLoop.hpp"

const std::optional<LibStarch::ASTInnerCode>& LibStarch::ASTForLoop::getInit() const {
    return init;
}

const std::optional<LibStarch::ASTInnerCode>& LibStarch::ASTForLoop::getStep() const {
    return step;
}

LibStarch::ASTForLoop::ASTForLoop(const CondNode& cond, const ASTInnerCode& code,
                                  std::optional<ASTInnerCode> init,
                                  std::optional<ASTInnerCode> step)
        : ASTLoop(cond, code), init(std::move(init)),
          step(std::move(step)) {}

void LibStarch::ASTForLoop::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

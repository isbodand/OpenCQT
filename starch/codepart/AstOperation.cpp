#include <utility>

//
// Created by bodand on 2019-07-01.
//

#include "AstOperation.hpp"

LibStarch::ASTOperation::ASTOperation(Instruction instr, Ptr<ValNode> rep,
                                      const std::optional<LibStarch::TypeCtor>& ctor)
        : instr(instr),
          rep(std::move(rep)),
          ctor() {
    if (ctor) {
        *this->ctor = *ctor;
    }
}

LibStarch::Instruction LibStarch::ASTOperation::getInstr() const {
    return instr;
}

const LibStarch::ValNode& LibStarch::ASTOperation::getRep() const {
    return *rep;
}

const std::optional<LibStarch::TypeCtor>& LibStarch::ASTOperation::getCtor() const {
    return ctor;
}

void LibStarch::ASTOperation::accept(Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

LibStarch::ValNode& LibStarch::ASTOperation::getRep() {
    return *rep;
}

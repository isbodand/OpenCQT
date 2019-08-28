//
// Created by bodand on 2019-07-01.
//

#include <utility>
#include "AstOperation.hpp"
#include "../val_subtrees/ValNumber.hpp"

LibStarch::ASTOperation::ASTOperation(Instruction instr, Ptr<ValNode> rep,
                                      std::optional<LibStarch::TypeCtor> ctor)
     : instr(instr),
       rep(std::move(rep)),
       ctor(std::move(ctor)),
       invId(std::nullopt),
       args() {
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

LibStarch::ASTOperation::ASTOperation(LibStarch::ValID id, std::vector<std::string> args)
     : instr(Utils::Impl::instInvocation),
       invId(std::move(id)),
       rep(new ValNumber(1)),
       ctor(std::nullopt),
       args(std::move(args)) {
}

const std::optional<LibStarch::ValID>& LibStarch::ASTOperation::getInvId() const {
    return invId;
}

std::optional<LibStarch::ValID>& LibStarch::ASTOperation::getInvId() {
    return invId;
}

const std::vector<std::string>& LibStarch::ASTOperation::getArgs() const {
    return args;
}

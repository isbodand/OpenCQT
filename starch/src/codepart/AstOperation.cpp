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

std::optional<LibStarch::TypeCtor>& LibStarch::ASTOperation::getCtor() {
    return ctor;
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

LibStarch::ASTOperation::Builder LibStarch::ASTOperation::getBuilder() {
    return ASTOperation::Builder();
}


LibStarch::ASTOperation::Builder::InstrBuilder
LibStarch::ASTOperation::Builder::asInstruction(Instruction instr) {
    return InstrBuilder(instr);
}

LibStarch::ASTOperation::Builder::CallBuilder
LibStarch::ASTOperation::Builder::asFunctionCall(LibStarch::ValID id) {
    return CallBuilder(std::move(id));
}

LibStarch::ASTOperation LibStarch::ASTOperation::Builder::InstrBuilder::build() const {
    return LibStarch::ASTOperation(instr, rep, _ctor);
}

LibStarch::Ptr<LibStarch::ASTOperation>
LibStarch::ASTOperation::Builder::InstrBuilder::buildPtr() const {
    return std::make_shared<LibStarch::ASTOperation>(instr, rep, _ctor);
}

LibStarch::ASTOperation::Builder::InstrBuilder::InstrBuilder(LibStarch::Instruction instr)
     : instr(instr) {}

LibStarch::ASTOperation::Builder::InstrBuilder&
LibStarch::ASTOperation::Builder::InstrBuilder::withRepetition(LibStarch::ValNode* val) {
    rep = Ptr<ValNode>(val);
    return *this;
}

LibStarch::ASTOperation::Builder::InstrBuilder&
LibStarch::ASTOperation::Builder::InstrBuilder::withRepetition(Ptr<LibStarch::ValNode> val) {
    rep = std::move(val);
    return *this;
}

LibStarch::ASTOperation::Builder::InstrBuilder&
LibStarch::ASTOperation::Builder::InstrBuilder::withConstructor(LibStarch::TypeCtor ctor) {
    _ctor = ctor;
    return *this;
}

LibStarch::ASTOperation::Builder::InstrBuilder&
LibStarch::ASTOperation::Builder::InstrBuilder::withConstructor(LibStarch::Utils::Type type, LibStarch::ValNode* val) {
    _ctor = TypeCtor(type, val);
    return *this;
}

LibStarch::ASTOperation::Builder::CallBuilder::CallBuilder(LibStarch::ValID id)
     : id(std::move(id)) {}

LibStarch::ASTOperation LibStarch::ASTOperation::Builder::CallBuilder::build() const {
    return LibStarch::ASTOperation(id, args);
}

LibStarch::ASTOperation::Builder::CallBuilder&
LibStarch::ASTOperation::Builder::CallBuilder::addArgument(const std::string& arg) {
    args.push_back(arg);
    return *this;
}

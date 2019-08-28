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

LibStarch::ASTRoot::Builder LibStarch::ASTRoot::getBuilder() {
    return LibStarch::ASTRoot::Builder();
}

LibStarch::ASTRoot LibStarch::ASTRoot::Builder::operator()() const {
    return this->build();
}

LibStarch::ASTRoot LibStarch::ASTRoot::Builder::build() const {
    if (code) {
        return LibStarch::ASTRoot(*code);
    }
    return LibStarch::ASTRoot(ASTCode{});
}

LibStarch::ASTRoot::Builder& LibStarch::ASTRoot::Builder::withCode(ASTCode&& in_code) {
    code = std::move(in_code);
    return *this;
}

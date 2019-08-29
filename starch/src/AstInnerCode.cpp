//
// Created by bodand on 2019-07-01.
//

#include "AstInnerCode.hpp"

#include <utility>

std::vector<LibStarch::Ptr<LibStarch::ASTCodePart>>& LibStarch::ASTInnerCode::getParts() {
    return parts;
}

const std::vector<LibStarch::Ptr<LibStarch::ASTCodePart>>& LibStarch::ASTInnerCode::getParts() const {
    return parts;
}

void LibStarch::ASTInnerCode::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

LibStarch::ASTInnerCode::ASTInnerCode(std::initializer_list<Ptr<ASTCodePart>> parts)
     : parts(parts) {}

LibStarch::ASTInnerCode::ASTInnerCode(std::vector<Ptr<ASTCodePart>> parts)
     : parts(std::move(parts)) {}

LibStarch::ASTInnerCode::Builder&
LibStarch::ASTInnerCode::Builder::addPart(Ptr<LibStarch::ASTCodePart>&& part) {
    codes.push_back(std::forward<Ptr<LibStarch::ASTCodePart>>(part));
    return *this;
}

LibStarch::ASTInnerCode LibStarch::ASTInnerCode::Builder::build() const {
    return LibStarch::ASTInnerCode(codes);
}

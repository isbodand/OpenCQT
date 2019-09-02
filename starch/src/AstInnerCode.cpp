//
// Created by bodand on 2019-07-01.
//

#include "AstInnerCode.hpp"

#include <utility>

std::vector<LibStarch::Ptr<LibStarch::ASTRestrictedCodePart>>& LibStarch::ASTInnerCode::getParts() {
    return parts;
}

const std::vector<LibStarch::Ptr<LibStarch::ASTRestrictedCodePart>>& LibStarch::ASTInnerCode::getParts() const {
    return parts;
}

void LibStarch::ASTInnerCode::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

LibStarch::ASTInnerCode::ASTInnerCode(std::initializer_list<Ptr<ASTRestrictedCodePart>> parts)
     : parts(parts) {}

LibStarch::ASTInnerCode::ASTInnerCode(std::vector<Ptr<ASTRestrictedCodePart>> parts)
     : parts(std::move(parts)) {}

LibStarch::ASTInnerCode::Builder&
LibStarch::ASTInnerCode::Builder::addPart(Ptr<LibStarch::ASTRestrictedCodePart>&& part) {
    codes.push_back(std::forward<Ptr<LibStarch::ASTRestrictedCodePart>>(part));
    return *this;
}

LibStarch::ASTInnerCode LibStarch::ASTInnerCode::Builder::build() const {
    return LibStarch::ASTInnerCode(codes);
}

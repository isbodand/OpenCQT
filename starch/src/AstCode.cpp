#include <utility>

//
// Created by bodand on 2019-07-01.
//

#include "AstCode.hpp"

void LibStarch::ASTCode::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

std::vector<LibStarch::Ptr<LibStarch::ASTExtendedCodePart>>& LibStarch::ASTCode::getParts() {
    return parts;
}

const std::vector<LibStarch::Ptr<LibStarch::ASTExtendedCodePart>>& LibStarch::ASTCode::getParts() const {
    return parts;
}

LibStarch::ASTCode::ASTCode(std::initializer_list<LibStarch::Ptr<LibStarch::ASTExtendedCodePart>> parts)
     : parts(parts) {}

LibStarch::ASTCode::ASTCode(std::vector<LibStarch::Ptr<LibStarch::ASTExtendedCodePart>> parts)
     : parts(std::move(parts)) {}

LibStarch::ASTCode::Builder LibStarch::ASTCode::getBuilder() {
    return LibStarch::ASTCode::Builder();
}

LibStarch::ASTCode LibStarch::ASTCode::Builder::build() const {
    return LibStarch::ASTCode(codes);
}

LibStarch::ASTCode::Builder&
LibStarch::ASTCode::Builder::addPart(LibStarch::Ptr<LibStarch::ASTExtendedCodePart>&& part) {
    codes.push_back(std::forward<std::decay_t<decltype(part)>>(part));
    return *this;
}

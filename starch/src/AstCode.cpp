//
// Created by bodand on 2019-07-01.
//

#include <utility>
#include <algorithm>

#include "AstCode.hpp"

void LibStarch::ASTCode::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

std::vector<LibStarch::Ptr<LibStarch::ASTCodePart>>& LibStarch::ASTCode::getParts() {
    return parts;
}

const std::vector<LibStarch::Ptr<LibStarch::ASTCodePart>>& LibStarch::ASTCode::getParts() const {
    return parts;
}

template<class CodeType, typename>
LibStarch::ASTCode::ASTCode(std::initializer_list<LibStarch::Ptr<CodeType>> parts)
     : parts(
     ([parts]() {
       std::vector<std::shared_ptr<ASTCodePart>> retVal;
       std::transform(parts.begin(), parts.end(), retVal.begin(), [](Ptr <CodeType> ptr) {
         return std::static_pointer_cast<ASTCodePart>(ptr);
       });
       return retVal;
     })()) {
}

template<class CodeType, typename>
LibStarch::ASTCode::ASTCode(std::vector<LibStarch::Ptr<CodeType>> parts)
     : parts(std::move(
     ([parts]() {
       std::vector<std::shared_ptr<ASTCodePart>> retVal;
       std::transform(parts.cbegin(), parts.cend(), retVal.begin(), [](Ptr <CodeType> ptr) {
         return std::static_pointer_cast<ASTCodePart>(ptr);
       });
       return retVal;
     })())) {
}

LibStarch::ASTCode::Builder LibStarch::ASTCode::getBuilder() {
    return LibStarch::ASTCode::Builder();
}

LibStarch::ASTCode LibStarch::ASTCode::Builder::build() const {
    return LibStarch::ASTCode(codes);
}

LibStarch::ASTCode::Builder&
LibStarch::ASTCode::Builder::addPart(LibStarch::Ptr<LibStarch::ASTCodePart>&& part) {
    codes.push_back(std::forward<std::decay_t<decltype(part)>>(part));
    return *this;
}

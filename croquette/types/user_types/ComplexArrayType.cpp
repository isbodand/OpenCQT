#include <utility>

//
// Created by bodand on 2019-03-25.
//

#include "ComplexArrayType.hpp"

LibCqt::ComplexArrayType::ComplexArrayType() = default;

LibCqt::String LibCqt::ComplexArrayType::printStart() const {
    return CQT_STRING("(");
}

LibCqt::String LibCqt::ComplexArrayType::printEnd() const {
    return CQT_STRING(")");
}

LibCqt::ComplexArrayType::ComplexArrayType(const LibCqt::Ptr<LibCqt::ComplexArrayType>& copy)
        : ArrayArchetype(*copy) {}

LibCqt::ComplexArrayType::ComplexArrayType(std::initializer_list<LibCqt::Ptr<LibCqt::AnyArchetype>> init)
        : ArrayArchetype(init) {}

LibCqt::ComplexArrayType::ComplexArrayType(std::vector<LibCqt::Ptr<LibCqt::AnyArchetype>> init)
        : ArrayArchetype(std::move(init)) {}

LibCqt::ArrayType LibCqt::ComplexArrayType::getArrayType() const {
    return arrayComplexArray;
}

//&!off
LibCqt::ComplexArrayType::ComplexArrayType(LibCqt::ArrayArchetype<LibCqt::ComplexArrayType::T,
                                                                  LibCqt::ComplexArrayType::U>& cpa)
    : ArrayArchetype(cpa) {}
//&!on

LibCqt::ComplexArrayType::ComplexArrayType(const std::vector<LibCqt::ComplexArrayType::T>*& init) {
    for (auto&& cell : *init) {
        cells.push_back(mkPtr<T>(cell));
    }
}

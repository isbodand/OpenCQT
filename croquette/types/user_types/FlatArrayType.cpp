#include <utility>

//
// Created by bodand on 2019-03-25.
//

#include "FlatArrayType.hpp"

LibCqt::FlatArrayType::FlatArrayType() = default;

LibCqt::String LibCqt::FlatArrayType::printStart() const {
    return CQT_STRING("$(");
}

LibCqt::String LibCqt::FlatArrayType::printEnd() const {
    return CQT_STRING(")");
}

LibCqt::FlatArrayType::FlatArrayType(CRf<LibCqt::Ptr<LibCqt::FlatArrayType>> copy)
        : ArrayArchetype(copy.get()) {}

LibCqt::FlatArrayType::FlatArrayType(std::initializer_list<LibCqt::Ptr<LibCqt::ScalarArchetype>> init)
        : ArrayArchetype(init) {}

LibCqt::FlatArrayType::FlatArrayType(std::vector<LibCqt::Ptr<LibCqt::ScalarArchetype>> init)
        : ArrayArchetype(std::move(init)) {}

LibCqt::ArrayType LibCqt::FlatArrayType::getArrayType() const {
    return arrayFlatArray;
}

//&!off
LibCqt::FlatArrayType::FlatArrayType(LibCqt::ArrayArchetype<LibCqt::FlatArrayType::T,
                                                            LibCqt::FlatArrayType::U>& cpa)
    : ArrayArchetype(cpa) {}
//&!on

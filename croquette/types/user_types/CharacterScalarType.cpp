//
// Created by bodand on 2019-03-25.
//

#include <cmath>
#include "CharacterScalarType.hpp"

LibCqt::CharacterScalarType::CharacterScalarType() : ScalarArchetype(32) {}

LibCqt::String LibCqt::CharacterScalarType::asString() {
    StringStream stream;
    stream << CQT_CHAR('\'') << (char) std::floor(value) << CQT_CHAR('\'');
    return std::move(stream.str());
}

LibCqt::CharacterScalarType::CharacterScalarType(double value) : ScalarArchetype(value) {}

LibCqt::CharacterScalarType::CharacterScalarType(CRf<LibCqt::ScalarArchetype> copy)
        : ScalarArchetype(copy) {
}

LibCqt::CharacterScalarType::CharacterScalarType(CRf<LibCqt::Ptr<LibCqt::ScalarArchetype>> ref)
        : ScalarArchetype(ref) {
}

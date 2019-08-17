//
// Created by bodand on 2019-03-25.
//

#include <cmath>
#include <codecvt>
#include <locale>
#include "CharacterScalarType.hpp"

LibCqt::CharacterScalarType::CharacterScalarType()
        : ScalarArchetype(32) {}

LibCqt::String LibCqt::CharacterScalarType::asString() const {
    StringStream stream;
    stream << CQT_CHAR('\'') << (Char) std::floor(value) << CQT_CHAR('\'');
    return std::move(stream.str());
}

LibCqt::CharacterScalarType::CharacterScalarType(double value)
        : ScalarArchetype(value) {}

LibCqt::CharacterScalarType::CharacterScalarType(const LibCqt::Ptr<LibCqt::ScalarArchetype>& ref)
        : ScalarArchetype(ref) {}

LibCqt::CharacterScalarType::CharacterScalarType(LibCqt::ScalarArchetype& cpa)
        : ScalarArchetype(cpa) {}

LibCqt::CharacterScalarType& LibCqt::CharacterScalarType::operator=(LibCqt::ScalarArchetype& cpa) noexcept {
    *static_cast<ScalarArchetype*>(this) = cpa;
    return *this;
}

LibCqt::CharacterScalarType& LibCqt::CharacterScalarType::operator=(LibCqt::ScalarArchetype&& mva) noexcept {
    *static_cast<ScalarArchetype*>(this) = std::move(mva);
    return *this;
}

LibCqt::ScalarType LibCqt::CharacterScalarType::getScalarType() const {
    return scalarCharacterScalar;
}

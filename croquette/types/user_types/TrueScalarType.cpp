//
// Created by bodand on 2019-03-25.
//

#include <codecvt>
#include <locale>
#include "TrueScalarType.hpp"

LibCqt::TrueScalarType::TrueScalarType()
        : ScalarArchetype() {}

LibCqt::TrueScalarType::TrueScalarType(double value)
        : ScalarArchetype(value) {}

LibCqt::TrueScalarType::TrueScalarType(const LibCqt::Ptr<LibCqt::ScalarArchetype>& ref)
        : ScalarArchetype(ref) {}

LibCqt::TrueScalarType::TrueScalarType(LibCqt::ScalarArchetype& cp)
        : ScalarArchetype(cp) {
}

LibCqt::TrueScalarType& LibCqt::TrueScalarType::operator=(LibCqt::ScalarArchetype& cpa) noexcept {
    *static_cast<ScalarArchetype*>(this) = cpa;
    return *this;
}

LibCqt::TrueScalarType& LibCqt::TrueScalarType::operator=(LibCqt::ScalarArchetype&& mva) noexcept {
    *static_cast<ScalarArchetype*>(this) = std::move(mva);
    return *this;
}

LibCqt::ScalarType LibCqt::TrueScalarType::getScalarType() const {
    return scalarTrueScalar;
}

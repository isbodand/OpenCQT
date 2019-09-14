//
// Created by bodand on 2019-03-25.
//

#include <codecvt>
#include <locale>
#include "ScalarArchetype.hpp"
#include "AnyArchetype.hpp"

LibCqt::ScalarArchetype::ScalarArchetype()
        : AnyArchetype(LibCqt::archScalar), value(0) {}

LibCqt::ScalarArchetype::ScalarArchetype(double value)
        : value(value) {}

double LibCqt::ScalarArchetype::getValue() const {
    return value;
}

LibCqt::ScalarArchetype::ScalarArchetype(const LibCqt::Ptr<LibCqt::ScalarArchetype>& ref)
        : ScalarArchetype(ref->getValue()) {
}

void LibCqt::ScalarArchetype::setValue(double _value) {
    value = _value;
}

bool LibCqt::ScalarArchetype::operator==(const LibCqt::ScalarArchetype& rhs) const {
    return static_cast<const AnyArchetype&>(*this) == static_cast<const AnyArchetype&>(rhs) &&
           getScalarType() == rhs.getScalarType() &&
           value == rhs.value;
}

bool LibCqt::ScalarArchetype::operator!=(const LibCqt::ScalarArchetype& rhs) const {
    return !(rhs == *this);
}

bool LibCqt::ScalarArchetype::operator<(const LibCqt::ScalarArchetype& rhs) const {
    return value < rhs.value;
}

bool LibCqt::ScalarArchetype::operator>(const LibCqt::ScalarArchetype& rhs) const {
    return rhs < *this;
}

bool LibCqt::ScalarArchetype::operator<=(const LibCqt::ScalarArchetype& rhs) const {
    return !(rhs < *this);
}

bool LibCqt::ScalarArchetype::operator>=(const LibCqt::ScalarArchetype& rhs) const {
    return !(*this < rhs);
}

LibCqt::String LibCqt::ScalarArchetype::asString() const {
    auto str = std::move(CQT_TO_STRING(value));
    auto firstzero = str.find(CQT_CHAR('0'), str.find(CQT_CHAR('.')));
    str = std::move(str.substr(0, firstzero));
    if (str.back() == CQT_CHAR('.'))
        str = std::move(str.substr(0, str.size() - 1));
    return std::move(str);
}

bool LibCqt::ScalarArchetype::operator==(const double& rhs) const {
    return value == rhs;
}

bool LibCqt::ScalarArchetype::operator!=(const double& rhs) const {
    return value != rhs;
}

bool LibCqt::ScalarArchetype::operator<(const double& rhs) const {
    return value < rhs;
}

bool LibCqt::ScalarArchetype::operator>(const double& rhs) const {
    return value > rhs;
}

bool LibCqt::ScalarArchetype::operator<=(const double& rhs) const {
    return value <= rhs;
}

bool LibCqt::ScalarArchetype::operator>=(const double& rhs) const {
    return value >= rhs;
}

LibCqt::ScalarType LibCqt::ScalarArchetype::getScalarType() const {
    return scalarAnyScalar;
}


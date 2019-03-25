//
// Created by bodand on 2019-03-25.
//

#include "TrueScalarType.hpp"

LibCqt::TrueScalarType::TrueScalarType() : ScalarArchetype() {}

LibCqt::String LibCqt::TrueScalarType::asString() {
    StringStream stream;
    stream << value;
    return std::move(stream.str());
}

LibCqt::TrueScalarType::TrueScalarType(double value) : ScalarArchetype(value) {}

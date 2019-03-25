//
// Created by bodand on 2019-03-25.
//

#include "ComplexArrayType.hpp"

LibCqt::ComplexArrayType::ComplexArrayType() = default;

LibCqt::String LibCqt::ComplexArrayType::printStart() {
    return CQT_STRING("(");
}

LibCqt::String LibCqt::ComplexArrayType::printEnd() {
    return CQT_STRING(")");
}

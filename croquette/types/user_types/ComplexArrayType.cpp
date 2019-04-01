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

LibCqt::ComplexArrayType::ComplexArrayType(CRf<LibCqt::Ptr<LibCqt::ComplexArrayType>> copy)
        : ArrayArchetype(*copy) {
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-use-equals-default"

LibCqt::ComplexArrayType::ComplexArrayType(CRf<LibCqt::ComplexArrayType> copy)
        : ArrayArchetype(copy) {
}

#pragma clang diagnostic pop

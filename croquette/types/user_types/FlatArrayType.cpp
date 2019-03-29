//
// Created by bodand on 2019-03-25.
//

#include "FlatArrayType.hpp"

LibCqt::FlatArrayType::FlatArrayType() = default;

LibCqt::String LibCqt::FlatArrayType::printStart() {
    return CQT_STRING("$(");
}

LibCqt::String LibCqt::FlatArrayType::printEnd() {
    return CQT_STRING(")");
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-use-equals-default"

LibCqt::FlatArrayType::FlatArrayType(const LibCqt::FlatArrayType& copy) : ArrayArchetype(copy) {}

#pragma clang diagnostic pop

LibCqt::FlatArrayType::FlatArrayType(const LibCqt::Ptr<LibCqt::FlatArrayType>& copy) : ArrayArchetype(copy.get()) {}

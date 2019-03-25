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

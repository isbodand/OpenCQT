//
// Created by bodand on 2019-04-01.
//

#include "OrderedMapType.hpp"

LibCqt::OrderedMapType::OrderedMapType() = default;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-use-equals-default"

LibCqt::OrderedMapType::OrderedMapType(LibCqt::CRf<LibCqt::OrderedMapType> copy) : HashArchetype(copy) {
}

#pragma clang diagnostic pop

LibCqt::OrderedMapType::OrderedMapType(LibCqt::CRf<LibCqt::Ptr<LibCqt::OrderedMapType>> ptrCopy)
        : HashArchetype(*ptrCopy) {
}

LibCqt::String LibCqt::OrderedMapType::printStart() {
    return CQT_STRING("@(");
}

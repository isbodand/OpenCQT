//
// Created by bodand on 2019-04-01.
//

#include "HashmapType.hpp"

LibCqt::HashmapType::HashmapType() = default;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-use-equals-default"

LibCqt::HashmapType::HashmapType(LibCqt::CRf<LibCqt::HashmapType> copy) : HashArchetype(copy) {
}

#pragma clang diagnostic pop

LibCqt::HashmapType::HashmapType(LibCqt::CRf<LibCqt::Ptr<LibCqt::HashmapType>> copy) : HashArchetype(*copy) {
}

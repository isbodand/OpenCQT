//
// Created by bodand on 2019-04-01.
//

#include "OrderedMapType.hpp"

LibCqt::OrderedMapType::OrderedMapType(LibCqt::CRf<LibCqt::Ptr<LibCqt::OrderedMapType>> ptrCopy)
        : OrderedMapType(*ptrCopy) {}

LibCqt::String LibCqt::OrderedMapType::printStart() const {
    return CQT_STRING("@(");
}

LibCqt::OrderedMapType::OrderedMapType(LibCqt::HashArchetype<LibCqt::Map>& cpa)
        : HashArchetype(cpa) {}

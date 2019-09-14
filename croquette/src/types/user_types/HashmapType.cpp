//
// Created by bodand on 2019-04-01.
//

#include "HashmapType.hpp"

LibCqt::HashmapType::HashmapType(const LibCqt::Ptr<LibCqt::HashmapType>& ptrcp)
        : HashmapType(*ptrcp) {
}

LibCqt::HashmapType::HashmapType(LibCqt::HashArchetype<LibCqt::Hashmap>& cpa)
        : HashArchetype(cpa) {
}

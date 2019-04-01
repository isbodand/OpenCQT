//
// Created by bodand on 2019-04-01.
//

#pragma once

#include "../ImplementationTypes.hpp"
#include "../archetypes/HashArchetype.hpp"

namespace LibCqt {
    class HashmapType : public HashArchetype<Hashmap> {
    public:
        using T = Hashmap<String, AnyArchetype_P>;
        using U = void;
        using Archetype = HashArchetype<Hashmap>;

        HashmapType();
        HashmapType(CRf<HashmapType> copy);
        explicit HashmapType(CRf<Ptr<HashmapType>> copy);
    };
}

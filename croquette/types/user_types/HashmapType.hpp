//
// Created by bodand on 2019-04-01.
//

#pragma once

#include "../ImplementationTypes.hpp"
#include "../archetypes/HashArchetype.hpp"

namespace LibCqt {
    class HashmapType : public HashArchetype<Hashmap> {
    public: // Types
        using T = Hashmap<String, AnyArchetype_P>;
        using U = void;
        using Archetype = HashArchetype<Hashmap>;
        using _Archetype = HashArchetype;

    public: // Constructors & destructor
        HashmapType() = default;
        HashmapType(Ref<HashmapType> cp) = default;
        HashmapType(RRf<HashmapType> mv) noexcept = default;
        explicit HashmapType(CRf<Ptr<HashmapType>> ptrcp);
        HashmapType(Ref<HashArchetype<Hashmap>> cpa);

    public: // Operators
        HashmapType& operator=(Ref<HashmapType> cp) = default;
        HashmapType& operator=(RRf<HashmapType> mv) noexcept = default;
    };
}

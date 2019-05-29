//
// Created by bodand on 2019-04-01.
//

#pragma once

#include "../archetypes/HashArchetype.hpp"

namespace LibCqt {
    class OrderedMapType : public HashArchetype<Map> {
    public: // Types
        using T = Map<String, AnyArchetype_P>;
        using U = void;
        using Archetype = HashArchetype<Map>;
        using _Archetype = HashArchetype;

    protected: // Overridden protected methods
        String printStart() const override;

    public: // Constructors & destructor
        OrderedMapType() = default;
        OrderedMapType(Ref<OrderedMapType> cp) = default;
        OrderedMapType(RRf<OrderedMapType> mv) noexcept = default;
        explicit OrderedMapType(CRf<Ptr<OrderedMapType>> ptrCopy);
        OrderedMapType(Ref<HashArchetype<Map>> cpa);

    public: // Operators
        OrderedMapType& operator=(Ref<OrderedMapType> cp) = default;
        OrderedMapType& operator=(RRf<OrderedMapType> mv) noexcept = default;
    };
}



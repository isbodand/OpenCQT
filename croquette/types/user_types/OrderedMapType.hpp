//
// Created by bodand on 2019-04-01.
//

#pragma once

#include "../archetypes/HashArchetype.hpp"

namespace LibCqt {
    class OrderedMapType : public HashArchetype<Map> {

    public:
        using T = Map<String, AnyArchetype_P>;
        using U = void;
        using Archetype = HashArchetype<Map>;

    protected:
        String printStart() override;
    public:

        OrderedMapType();
        OrderedMapType(CRf<OrderedMapType> copy);
        explicit OrderedMapType(CRf<Ptr<OrderedMapType>> ptrCopy);
    };
}



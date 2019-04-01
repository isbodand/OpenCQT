//
// Created by bodand on 2019-03-25.
//

#pragma once

#include "../archetypes/ArrayArchetype.hpp"
#include "../archetypes/ScalarArchetype.hpp"
#include "TrueScalarType.hpp"

namespace LibCqt {
    class FlatArrayType : public ArrayArchetype<ScalarArchetype, TrueScalarType> {
    public:
        using T = ScalarArchetype;
        using U = TrueScalarType;
        using Archetype = ArrayArchetype<T, U>;
    protected:
        String printStart() override;
        String printEnd() override;
    public:
        FlatArrayType();
        FlatArrayType(CRf<FlatArrayType> copy);
        explicit FlatArrayType(CRf<Ptr<FlatArrayType>> ref);
    };
}


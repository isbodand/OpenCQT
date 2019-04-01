//
// Created by bodand on 2019-03-25.
//

#pragma once

#include "../archetypes/AnyArchetype.hpp"
#include "../archetypes/ArrayArchetype.hpp"
#include "TrueScalarType.hpp"

namespace LibCqt {
    class ComplexArrayType : public ArrayArchetype<AnyArchetype, TrueScalarType> {
    public:
        using T = AnyArchetype;
        using U = TrueScalarType;
        using Archetype = ArrayArchetype<T, U>;
    protected:
        String printStart() override;
        String printEnd() override;
    public:
        ComplexArrayType();
        ComplexArrayType(CRf<ComplexArrayType> copy);
        explicit ComplexArrayType(CRf<Ptr<ComplexArrayType>> copy);
    };
}


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
    protected:
        String printStart() override;
        String printEnd() override;
    public:

        ComplexArrayType();
    };
}


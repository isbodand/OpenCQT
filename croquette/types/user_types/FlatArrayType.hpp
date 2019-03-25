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
    protected:
        String printStart() override;
        String printEnd() override;
    public:
        FlatArrayType();
    };
}


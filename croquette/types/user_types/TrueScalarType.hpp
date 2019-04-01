//
// Created by bodand on 2019-03-25.
//

#pragma once

#include "../archetypes/ScalarArchetype.hpp"

namespace LibCqt {
    class TrueScalarType : public ScalarArchetype {
    public:
        using T = void;
        using U = void;
        using Archetype = ScalarArchetype;

        String asString() override;
        TrueScalarType();
        explicit TrueScalarType(double value);
        explicit TrueScalarType(const ScalarArchetype& copy);
        explicit TrueScalarType(const Ptr <LibCqt::ScalarArchetype>& ref);
    };
}



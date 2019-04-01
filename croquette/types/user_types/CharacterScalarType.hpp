//
// Created by bodand on 2019-03-25.
//

#pragma once

#include "../archetypes/ScalarArchetype.hpp"

namespace LibCqt {
    class CharacterScalarType : public ScalarArchetype {
    public:
        using T = void;
        using U = void;
        using Archetype = ScalarArchetype;

        String asString() override;

        CharacterScalarType();
        explicit CharacterScalarType(double value);
        explicit CharacterScalarType(CRf<ScalarArchetype> copy);
        explicit CharacterScalarType(CRf<Ptr<LibCqt::ScalarArchetype>> ref);
    };
}


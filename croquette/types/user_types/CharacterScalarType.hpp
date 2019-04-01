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
        explicit CharacterScalarType(const ScalarArchetype& copy);
        explicit CharacterScalarType(const Ptr <LibCqt::ScalarArchetype>& ref);
    };
}


//
// Created by bodand on 2019-03-25.
//

#pragma once

#include <ostream>
#include "../archetypes/ScalarArchetype.hpp"

namespace LibCqt {
    class CharacterScalarType : public ScalarArchetype {
    public: // Type types
        using T = void;
        using U = void;
        using Archetype = ScalarArchetype;

    public: // Overridden methods
        ScalarType getScalarType() const override;

    public: // Constructors & destructor
        CharacterScalarType();
        CharacterScalarType(CRf<CharacterScalarType> cp) = default;
        CharacterScalarType(RRf<CharacterScalarType> mv) noexcept = default;
        explicit CharacterScalarType(double value);
        explicit CharacterScalarType(CRf<Ptr<LibCqt::ScalarArchetype>> ref);
        CharacterScalarType(Ref<ScalarArchetype> cpa);

        ~CharacterScalarType() override = default;

    public: // Operators
        CharacterScalarType& operator=(Ref<CharacterScalarType> cp) = default;
        CharacterScalarType& operator=(RRf<CharacterScalarType> mv) noexcept = default;
        CharacterScalarType& operator=(Ref<ScalarArchetype> cpa) noexcept override;
        CharacterScalarType& operator=(RRf<ScalarArchetype> mva) noexcept override;

    public: // Inherited methods
        String asString() const override;
    };
}


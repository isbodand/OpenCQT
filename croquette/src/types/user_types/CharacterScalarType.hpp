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
      CharacterScalarType(const CharacterScalarType& cp) = default;
      CharacterScalarType(CharacterScalarType&& mv) noexcept = default;
      explicit CharacterScalarType(double value);
      explicit CharacterScalarType(const Ptr <LibCqt::ScalarArchetype>& ref);
      CharacterScalarType(ScalarArchetype& cpa);

      ~CharacterScalarType() override = default;

  public: // Operators
      CharacterScalarType& operator=(CharacterScalarType& cp) = default;
      CharacterScalarType& operator=(CharacterScalarType&& mv) noexcept = default;
      CharacterScalarType& operator=(ScalarArchetype& cpa) noexcept override;
      CharacterScalarType& operator=(ScalarArchetype&& mva) noexcept override;

  public: // Inherited methods
      String asString() const override;
  };
}


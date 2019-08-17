//
// Created by bodand on 2019-03-25.
//

#pragma once

#include <ostream>
#include "../archetypes/ScalarArchetype.hpp"

namespace LibCqt {
  class TrueScalarType : public ScalarArchetype {
  public: // Type types
      using T = void;
      using U = void;
      using Archetype = ScalarArchetype;

  public: // Overridden methods
      ScalarType getScalarType() const override;

  public: // Constructors & destructor
      TrueScalarType();
      TrueScalarType(const TrueScalarType& cp) = default;
      TrueScalarType(TrueScalarType&& mv) noexcept = default;
      explicit TrueScalarType(double value);
      explicit TrueScalarType(const Ptr <LibCqt::ScalarArchetype>& ref);
      TrueScalarType(ScalarArchetype& cpa);

      virtual ~TrueScalarType() = default;

  public: // Operators
      TrueScalarType& operator=(TrueScalarType& cp) = default;
      TrueScalarType& operator=(TrueScalarType&& mv) noexcept = default;
      TrueScalarType& operator=(ScalarArchetype& cpa) noexcept override;
      TrueScalarType& operator=(ScalarArchetype&& mva) noexcept override;
  };
}



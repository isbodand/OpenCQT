//
// Created by bodand on 2019-03-25.
//

#pragma once

#include <initializer_list>
#include <vector>

#include "../archetypes/ArrayArchetype.hpp"
#include "../archetypes/ScalarArchetype.hpp"
#include "TrueScalarType.hpp"

namespace LibCqt {
  class FlatArrayType : public ArrayArchetype<ScalarArchetype, TrueScalarType> {
  public: // Types
      using T = ScalarArchetype;
      using U = TrueScalarType;
      using Archetype = ArrayArchetype<T, U>;

  public: // Overridden methods
      ArrayType getArrayType() const override;

  protected: // Overridden protected methods
      String printStart() const override;
      String printEnd() const override;

  public: // Constructors & destructor
      FlatArrayType();
      FlatArrayType(const FlatArrayType& cp) = default;
      FlatArrayType(FlatArrayType&& mv) noexcept = default;
      FlatArrayType(std::initializer_list<Ptr<T>> init);
      FlatArrayType(std::vector<Ptr<T>> init);
      explicit FlatArrayType(const Ptr<FlatArrayType>& ref);
      FlatArrayType(ArrayArchetype<T, U>& cpa);

      virtual ~FlatArrayType() = default;

  public: // Operators
      FlatArrayType& operator=(FlatArrayType& cp) = default;
      FlatArrayType& operator=(FlatArrayType&& mv) noexcept = default;
  };
}


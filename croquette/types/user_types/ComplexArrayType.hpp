//
// Created by bodand on 2019-03-25.
//

#pragma once

#include "../archetypes/AnyArchetype.hpp"
#include "../archetypes/ArrayArchetype.hpp"
#include "TrueScalarType.hpp"

namespace LibCqt {
  class ComplexArrayType : public ArrayArchetype<AnyArchetype, TrueScalarType> {
  public: // Types
      using T = AnyArchetype;
      using U = TrueScalarType;
      using Archetype = ArrayArchetype<T, U>;

  public: // Overridden methods
      ArrayType getArrayType() const override;

  protected: // Overridden protected methods
      String printStart() const override;
      String printEnd() const override;

  public: // Constructors & destructor
      ComplexArrayType();
      ComplexArrayType(const ComplexArrayType& cp) = default;
      ComplexArrayType(ComplexArrayType&& mv) noexcept = default;
      explicit ComplexArrayType(const Ptr <ComplexArrayType>& copy);
      ComplexArrayType(std::initializer_list<Ptr < T>>
      init);
      ComplexArrayType(std::vector<Ptr < T>>
      init);
      explicit ComplexArrayType(const std::vector<T>*& init);
      ComplexArrayType(ArrayArchetype <T, U>& cpa);

      virtual ~ComplexArrayType() = default;

  public: // Operators
      ComplexArrayType& operator=(ComplexArrayType& cp) = default;
      ComplexArrayType& operator=(ComplexArrayType&& mv) noexcept = default;


  };
}


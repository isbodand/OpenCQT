//
// Created by tudom on 2019. 05. 23..
//
#pragma once

#pragma clang diagnostic push
#pragma ide diagnostic ignored "google-explicit-constructor"

#include "../TrueScalarType.hpp"
#include "../CharacterScalarType.hpp"

namespace LibCqt::Casts {
  template<class S>
  class scalar_cast {
  };

  template<>
  class scalar_cast<TrueScalarType> {
      const TrueScalarType& scalar;
  public:
      explicit scalar_cast(const TrueScalarType& scalar);

      operator TrueScalarType() const;
      operator CharacterScalarType() const;
  };

  template<>
  class scalar_cast<CharacterScalarType> {
      const CharacterScalarType& scalar;
  public:
      explicit scalar_cast(const CharacterScalarType& scalar);

      operator TrueScalarType() const;
      operator CharacterScalarType() const;
  };

  ////

  inline scalar_cast<TrueScalarType>::scalar_cast(const TrueScalarType& scalar)
          : scalar(scalar) {}

  inline scalar_cast<TrueScalarType>::operator TrueScalarType() const {
      return std::move(TrueScalarType(scalar));
  }

  inline scalar_cast<TrueScalarType>::operator CharacterScalarType() const {
      ScalarArchetype arch = scalar; //slicing discards override operator= ?????
      return std::move(CharacterScalarType(arch));
  }

  inline scalar_cast<CharacterScalarType>::scalar_cast(const CharacterScalarType& scalar)
          : scalar(scalar) {}

  inline scalar_cast<CharacterScalarType>::operator TrueScalarType() const {
      ScalarArchetype arch = scalar; //slicing discards override operator= ?????
      return std::move(TrueScalarType(arch));
  }

  inline scalar_cast<CharacterScalarType>::operator CharacterScalarType() const {
      return std::move(CharacterScalarType(scalar));
  }
}


#pragma clang diagnostic pop

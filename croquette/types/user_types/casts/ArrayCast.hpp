//
// Created by tudom on 2019. 05. 23..
//

#pragma once
#pragma clang diagnostic push
#pragma ide diagnostic ignored "google-explicit-constructor"

#include "../ComplexArrayType.hpp"
#include "../FlatArrayType.hpp"
#include "../../archetypes/ArchetypeUtilities.hpp"

#include <functional>

namespace LibCqt::Casts {
  template<class A>
  class array_cast {
  };

  template<>
  class array_cast<FlatArrayType> {
      const FlatArrayType& array;
  public:
      explicit array_cast(const FlatArrayType& array);

      operator FlatArrayType() const;
      operator ComplexArrayType() const;
  };

  template<>
  class array_cast<ComplexArrayType> {
      const ComplexArrayType& array;
  public:
      array_cast(const ComplexArrayType& array);

      operator FlatArrayType() const;
      operator ComplexArrayType() const;
  };

  inline array_cast<ComplexArrayType>::array_cast(const ComplexArrayType& array)
          : array(array) {}

  inline array_cast<FlatArrayType>::array_cast(const FlatArrayType& array)
          : array(array) {}

  inline array_cast<FlatArrayType>::operator FlatArrayType() const {
      return std::move(FlatArrayType(array));
  }

  inline array_cast<FlatArrayType>::operator ComplexArrayType() const {
      ComplexArrayType cmplx;
      for (auto&& cell : array.getCells()) {
          cmplx.makeCellOfType<ScalarArchetype>(cell);
      }
      return std::move(cmplx);
  }

  inline array_cast<ComplexArrayType>::operator FlatArrayType() const {
      FlatArrayType flat;
      for (const Ptr<AnyArchetype>& cell : array.getCells()) {
          switch (cell->getCurrentType()) {
              case archScalar:
                  switch (cell->getScalarType()) {
                      case scalarAnyScalar:
                          flat.makeCellOfType<ScalarArchetype>(std::static_pointer_cast<ScalarArchetype>(cell));
                          break;
                      case scalarCharacterScalar:
                          flat.makeCellOfType<CharacterScalarType>(
                                  std::static_pointer_cast<CharacterScalarType>(cell));
                          break;
                      case scalarTrueScalar:flat.makeCell(std::static_pointer_cast<TrueScalarType>(cell));
                          break;
                  }
                  break;
              case archArray:
                  switch (cell->getArrayType()) {
                      case arrayAnyArray:
                      case arrayFlatArray:
                          flat.makeCell(std::move(archetype_cast<TrueScalarType>(
                                  std::static_pointer_cast<ArrayArchetype<>>(cell)
                          )));
                          break;
                      case arrayComplexArray:
                          flat.makeCell(std::move(archetype_cast<TrueScalarType>(
                                  std::static_pointer_cast<ComplexArrayType>(cell)
                          )));
                          break;
                  }
                  break;
              case archHash:break;
              case archReference:break;
          }
      }
      return std::move(flat);
  }

  inline array_cast<ComplexArrayType>::operator ComplexArrayType() const {
      return std::move(ComplexArrayType(array));
  }

}

#pragma clang diagnostic pop

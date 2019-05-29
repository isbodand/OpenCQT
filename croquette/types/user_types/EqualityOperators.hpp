//
// Created by tudom on 2019. 05. 23..
//

#pragma once

#include "../ImplementationTypes.hpp"
#include "../archetypes/ArrayArchetype.hpp"
#include "FlatArrayType.hpp"
#include "ComplexArrayType.hpp"

namespace LibCqt {
  // Arrays
  bool operator==(CRf<FlatArrayType>, CRf<ComplexArrayType>) {
      return false;
  }

  bool operator==(CRf<ComplexArrayType>, CRf<FlatArrayType>) {
      return false;
  }
}

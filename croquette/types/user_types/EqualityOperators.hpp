//
// Created by tudom on 2019. 05. 23..
//

#pragma once

#include "../ImplementationTypes.hpp"
#include "../archetypes/ArrayArchetype.hpp"
#include "FlatArrayType.hpp"
#include "ComplexArrayType.hpp"

namespace LibCqt {
  // just found these, hope they are not important
  // Arrays
  bool operator==(const FlatArrayType&, const ComplexArrayType&) {
      return false;
  }

  bool operator==(const ComplexArrayType&, const FlatArrayType&) {
      return false;
  }
}

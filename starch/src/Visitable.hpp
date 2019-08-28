//
// Created by tudom on 2019-05-29.
//

#pragma once

#include "Visitor.hpp"

namespace LibStarch::Visiting {
  class Visitable {
      /// Interface
  public:
      virtual void accept(Visitor& visitor) = 0;
  };
}

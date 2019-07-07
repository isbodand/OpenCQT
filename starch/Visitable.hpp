//
// Created by tudom on 2019-05-29.
//

#pragma once

#include "Visitor.hpp"

namespace LibStarch::Visiting {
  class Visitable {
  public: // Methods
      virtual void accept(Visitor& visitor) = 0;

  public: // Constructors & Destructor
      Visitable() = default;
      Visitable(const Visitable& cp) = default;
      Visitable(Visitable&& mv) noexcept = default;

      virtual ~Visitable() = default;

  public: // Operators
      Visitable& operator=(const Visitable& cp) = default;
      Visitable& operator=(Visitable&& mv) noexcept = default;
  };
}

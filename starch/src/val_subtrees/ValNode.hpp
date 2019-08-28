//
// Created by bodand on 2019-06-20.
//

#pragma once

#include <ostream>
#include "../Visitable.hpp"

namespace LibStarch {
  class ValNode : public Visiting::Visitable {
      /// Interface
  public:
      [[nodiscard]] virtual double eval() const = 0;
      virtual void asString(std::ostream& os) const = 0;
      [[nodiscard]] virtual std::string getVal() const = 0;

      /// Lifecycle
  protected:
      ValNode() = default;
      ValNode(const ValNode& cp) = default;
      ValNode(ValNode&& mv) noexcept = default;

  public:
      virtual ~ValNode() = default;

      /// Operators
  public:
      ValNode& operator=(const ValNode& cp) = default;
      ValNode& operator=(ValNode&& mv) noexcept = default;

      friend std::ostream& operator<<(std::ostream& os, const ValNode& node);
  };
}

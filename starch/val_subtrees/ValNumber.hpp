//
// Created by bodand on 2019-06-20.
//

#pragma once

#include <ostream>
#include "ValNode.hpp"

namespace LibStarch {
  class ValNumber : public ValNode {
  public: // Methods
      double getValue() const;
      double eval() const override;
      void asString(std::ostream& os) const override;
      void accept(Visiting::Visitor& visitor) override;

  public: // Constructors & Destructor
      ValNumber() = delete;
      ValNumber(double value);
      ValNumber(const ValNumber& cp) = default;
      ValNumber(ValNumber&& mv) noexcept = default;

      virtual ~ValNumber() = default;

  public: // Operators
      ValNumber& operator=(const ValNumber& cp) = default;
      ValNumber& operator=(ValNumber&& mv) noexcept = default;

  private: // Fields
      double value;

  private: // Methods
  };
}

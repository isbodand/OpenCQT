//
// Created by bodand on 2019-06-20.
//

#pragma once

#include <ostream>
#include "ValNode.hpp"

namespace LibStarch {
  class ValNumber final : public ValNode {
  public: // Methods
      [[nodiscard]] double getValue() const;
      [[nodiscard]] double eval() const override;
      void asString(std::ostream& os) const override;
      void accept(Visiting::Visitor& visitor) override;
      [[nodiscard]] std::string getVal() const override;

  public: // Constructors & Destructor
      ValNumber() = default;
      ValNumber(double value);
      ValNumber(const ValNumber& cp) = default;
      ValNumber(ValNumber&& mv) noexcept = default;

      ~ValNumber() override = default;

  public: // Operators
      ValNumber& operator=(const ValNumber& cp) = default;
      ValNumber& operator=(ValNumber&& mv) noexcept = default;

  private: // Fields
      double value;

  private: // Methods
  };
}

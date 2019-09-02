//
// Created by bodand on 2019-06-20.
//

#pragma once

#include <string>
#include <ostream>
#include "ValNode.hpp"

namespace LibStarch {
  class ValText final : public ValNode {
  public: // Methods
      [[nodiscard]] const std::string& getValue() const;
      [[nodiscard]] double eval() const override;
      void asString(std::ostream& os) const override;
      void accept(Visiting::Visitor& visitor) override;
      [[nodiscard]] std::string getVal() const override;

  public: // Constructors & Destructor
      ValText() = default;
      ValText(std::string value);
      ValText(const char* value);
      ValText(const ValText& cp) = default;
      ValText(ValText&& mv) noexcept = default;

      ~ValText() override = default;

  public: // Operators
      ValText& operator=(const ValText& cp) = default;
      ValText& operator=(ValText&& mv) noexcept = default;

  private: // Fields
      std::string value;
  };
}


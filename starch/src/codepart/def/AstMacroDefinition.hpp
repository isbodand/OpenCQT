//
// Created by bodand on 2019-08-24.
//

#pragma once

#include <vector>

#include "AstDefinition.hpp"

namespace LibStarch {
  class ASTMacroDefinition : public ASTDefinition {
      /// Interface
  public:
      [[nodiscard]] int getType() const override;
      [[nodiscard]] const std::string& getText() const;

      void accept(Visiting::Visitor& visitor) override;

      [[nodiscard]] std::string&& apply(const std::vector<std::string>& args) const;

      /// Lifecycle
  public:
      ASTMacroDefinition() = default;
      ASTMacroDefinition(const ValID& name, std::string text, std::vector<std::string> params);

      /// Fields
  private:
      std::vector<std::string> params;
      std::string text;
  };
}

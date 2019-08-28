//
// Created by bodand on 2019-08-24.
//

#pragma once


#include "AstDefinition.hpp"
#include "../../AstCode.hpp"
#include "../../Utils.hpp"

namespace LibStarch {
  class ASTSubDefinition : public ASTDefinition {
      /// Interface
  public:
      [[nodiscard]] int getType() const override;
      [[nodiscard]] const ASTCode& getCode() const;

      void accept(Visiting::Visitor& visitor) override;

      /// Lifecycle
  public:
      ASTSubDefinition() = delete;
      ASTSubDefinition(const ValID& name, Utils::ASTSubParams params, ASTCode code);

      /// Fields
  private:
      ASTCode code;
      Utils::ASTSubParams params;
  };
}


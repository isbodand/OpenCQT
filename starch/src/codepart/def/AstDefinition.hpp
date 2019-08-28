//
// Created by bodand on 2019-08-24.
//

#pragma once

#include "../AstExtendedCodePart.hpp"
#include "../../val_subtrees/ValId.hpp"

namespace LibStarch {
  class ASTDefinition : public ASTExtendedCodePart {
      /// Interface
  public:
      [[nodiscard]] const ValID& getName() const;
      [[nodiscard]] virtual int getType() const = 0;

      /// Lifecycle
  protected:
      ASTDefinition(ValID name);

      /// Fields
  private:
      ValID name;
  };
}

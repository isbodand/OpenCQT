//
// Created by bodand on 2019-07-01.
//

#pragma once

#include "../AstNode.hpp"

namespace LibStarch {
  class ASTCodePart : public ASTNode {
  };

  class ASTExtendedCodePart : public ASTCodePart {
  };

  class ASTRestrictedCodePart : public ASTCodePart {
  };
}

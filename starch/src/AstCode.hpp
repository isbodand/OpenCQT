//
// Created by bodand on 2019-07-01.
//

#pragma once

#include <initializer_list>
#include "AstNode.hpp"
#include "codepart/AstExtendedCodePart.hpp"
#include "Utils.hpp"

namespace LibStarch {
  using Utils::Ptr;
  using Utils::mkPtr;

  class ASTCode : public ASTNode {
      /// Interface
  public:
      void accept(Visiting::Visitor& visitor) override;
      [[nodiscard]] std::vector<Ptr<ASTExtendedCodePart>>& getParts();
      [[nodiscard]] const std::vector<Ptr<ASTExtendedCodePart>>& getParts() const;

      /// Lifecycle
  public:
      ASTCode() = default;
      ASTCode(std::initializer_list<Ptr<LibStarch::ASTExtendedCodePart>> parts);

      /// Fields
  private:
      std::vector<Ptr<ASTExtendedCodePart>> parts;
  };
}

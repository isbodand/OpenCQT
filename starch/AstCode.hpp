//
// Created by bodand on 2019-07-01.
//

#pragma once

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

      std::vector<Ptr<ASTExtendedCodePart>>& getParts();
      /// Constructors & Destructor
  public:
      ASTCode() = default;
      ASTCode(std::vector<Ptr<LibStarch::ASTExtendedCodePart>> parts);
      ASTCode(const ASTCode& cp) = default;
      ASTCode(ASTCode&& mv) noexcept = default;

      virtual ~ASTCode() = default;

      /// Operators
  public:
      ASTCode& operator=(const ASTCode& cp) = default;
      ASTCode& operator=(ASTCode&& mv) noexcept = default;

      /// Fields
  private:
      std::vector<Ptr<ASTExtendedCodePart>> parts;

      /// Methods
  private:
  };
}

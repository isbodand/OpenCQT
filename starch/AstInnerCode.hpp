//
// Created by bodand on 2019-07-01.
//

#pragma once

#include "AstNode.hpp"
#include "codepart/AstCodePart.hpp"
#include "Utils.hpp"
#include "Visitor.hpp"

namespace LibStarch {
  using Utils::Ptr;
  using Utils::mkPtr;

  class ASTInnerCode : public ASTNode {
  public: // Methods
      void accept(Visiting::Visitor& visitor) override;
      std::vector<Ptr<ASTCodePart>>& getParts();
      const std::vector<Ptr<ASTCodePart>>& getParts() const;

  public: // Constructors & Destructor
      ASTInnerCode() = default;
      ASTInnerCode(const ASTInnerCode& cp) = default;
      ASTInnerCode(ASTInnerCode&& mv) noexcept = default;

      virtual ~ASTInnerCode() = default;

  public: // Operators
      ASTInnerCode& operator=(const ASTInnerCode& cp) = default;
      ASTInnerCode& operator=(ASTInnerCode&& mv) noexcept = default;

  private: // Fields
      std::vector<Ptr<ASTCodePart>> parts;
  private: // Methods
  };
}

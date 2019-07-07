//
// Created by bodand on 2019-07-01.
//

#pragma once

#include "AstNode.hpp"
#include "AstCode.hpp"

namespace LibStarch {
  class ASTRoot : public ASTNode {
  public: // Methods
      void accept(Visiting::Visitor& visitor) override;

      ASTCode& getCode();

  public: // Constructors & Destructor
      ASTRoot() = default;
      ASTRoot(ASTCode code);
      ASTRoot(const ASTRoot& cp) = default;
      ASTRoot(ASTRoot&& mv) noexcept = default;

      virtual ~ASTRoot() = default;

  public: // Operators
      ASTRoot& operator=(const ASTRoot& cp) = default;
      ASTRoot& operator=(ASTRoot&& mv) noexcept = default;

  private: // Fields
      ASTCode code;
  private: // Methods
  };
}

//
// Created by bodand on 2019-07-01.
//

#pragma once

#include "AstLoop.hpp"

namespace LibStarch {
  class ASTWhileLoop : public ASTLoop {
      /// Interface
  public:
  private:
      void accept(Visiting::Visitor& visitor) override;

      /// Constructors & Destructor
  public:
      ASTWhileLoop() = default;
      ASTWhileLoop(const CondNode& cond, const ASTInnerCode& code);
      ASTWhileLoop(const ASTWhileLoop& cp) = default;
      ASTWhileLoop(ASTWhileLoop&& mv) noexcept = default;

      virtual ~ASTWhileLoop() = default;

      /// Operators
  public:
      ASTWhileLoop& operator=(const ASTWhileLoop& cp) = default;
      ASTWhileLoop& operator=(ASTWhileLoop&& mv) noexcept = default;

      /// Fields
  private:

      /// Methods
  private:
  };
}

//
// Created by bodand on 2019-07-01.
//

#pragma once

#include "AstLoop.hpp"

namespace LibStarch {
  class ASTDoLoop : public ASTLoop {
      /// Interface
  public:
  private:
      void accept(Visiting::Visitor& visitor) override;

      /// Constructors & Destructor
  public:
      ASTDoLoop() = default;
      ASTDoLoop(const CondNode& cond, const ASTInnerCode& code);
      ASTDoLoop(const ASTDoLoop& cp) = default;
      ASTDoLoop(ASTDoLoop&& mv) noexcept = default;

      virtual ~ASTDoLoop() = default;

      /// Operators
  public:
      ASTDoLoop& operator=(const ASTDoLoop& cp) = default;
      ASTDoLoop& operator=(ASTDoLoop&& mv) noexcept = default;

      /// Fields
  private:

      /// Methods
  private:
  };
}

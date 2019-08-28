//
// Created by bodand on 2019-07-01.
//

#pragma once

#include "AstLoop.hpp"

namespace LibStarch {
  class ASTWhileLoop : public ASTLoop {
      /// Lifecycle
  public:
      ASTWhileLoop() = delete;
      ASTWhileLoop(const CondNode& cond, const ASTInnerCode& code);
      ASTWhileLoop(const ASTWhileLoop& cp) = default;
      ASTWhileLoop(ASTWhileLoop&& mv) noexcept = default;

      ~ASTWhileLoop() override = default;

      /// Operators
  public:
      ASTWhileLoop& operator=(const ASTWhileLoop& cp) = default;
      ASTWhileLoop& operator=(ASTWhileLoop&& mv) noexcept = default;

      /// Methods
  private:
      void accept(Visiting::Visitor& visitor) override;
  };
}

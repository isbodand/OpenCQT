//
// Created by bodand on 2019-07-01.
//

#pragma once

#include <utility>
#include "../AstCodePart.hpp"
#include "../../CondNode.hpp"
#include "../../AstInnerCode.hpp"

namespace LibStarch {
  class ASTLoop : public ASTRestrictedCodePart {
      /// Interface
  public:
      [[nodiscard]] const CondNode& getCond() const;
      [[nodiscard]] const ASTInnerCode& getCode() const;

      /// Lifecycle
  protected:
      ASTLoop() = default;
      ASTLoop(CondNode cond, ASTInnerCode code);
      ASTLoop(const ASTLoop& cp) = default;
      ASTLoop(ASTLoop&& mv) noexcept = default;

  public:
      ~ASTLoop() override = default;

      /// Operators
  public:
      ASTLoop& operator=(const ASTLoop& cp) = default;
      ASTLoop& operator=(ASTLoop&& mv) noexcept = default;

      /// Fields
  private:
      CondNode cond;
      ASTInnerCode code;
  };

  inline const CondNode& ASTLoop::getCond() const {
      return cond;
  }

  inline const ASTInnerCode& ASTLoop::getCode() const {
      return code;
  }

  inline ASTLoop::ASTLoop(CondNode cond, ASTInnerCode code)
          : cond(std::move(cond)), code(std::move(code)) {}
}

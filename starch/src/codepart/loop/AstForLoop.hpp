#include <utility>

#include <utility>

#include <utility>

#include <utility>

//
// Created by bodand on 2019-07-01.
//

#pragma once

#include <optional>
#include "AstLoop.hpp"

namespace LibStarch {
  class ASTForLoop : public ASTLoop {
      /// Interface
  public:
      [[nodiscard]] const std::optional<ASTInnerCode>& getInit() const;
      [[nodiscard]] const std::optional<ASTInnerCode>& getStep() const;
  private:
      void accept(Visiting::Visitor& visitor) override;

      /// Lifecycle
  public:
      ASTForLoop() = default;
      ASTForLoop(const CondNode& cond, const ASTInnerCode& code,
                 std::optional<ASTInnerCode> init = std::nullopt,
                 std::optional<ASTInnerCode> step = std::nullopt);
      ASTForLoop(const ASTForLoop& cp) = default;
      ASTForLoop(ASTForLoop&& mv) noexcept = default;

      ~ASTForLoop() override = default;

      /// Operators
  public:
      ASTForLoop& operator=(const ASTForLoop& cp) = default;
      ASTForLoop& operator=(ASTForLoop&& mv) noexcept = default;

      /// Fields
  private:
      std::optional<ASTInnerCode> init;
      std::optional<ASTInnerCode> step;
  };
}

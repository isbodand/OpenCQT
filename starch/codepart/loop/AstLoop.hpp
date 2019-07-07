//
// Created by bodand on 2019-07-01.
//

#pragma once

#include <utility>
#include "../AstCodePart.hpp"
#include "../../CondNode.hpp"
#include "../AstExtendedCodePart.hpp"
#include "../../AstInnerCode.hpp"

namespace LibStarch {
  class ASTLoop : public ASTCodePart,
                  public ASTExtendedCodePart {
  public: // Methods
      const CondNode& getCond() const;
      const ASTInnerCode& getCode() const;

  protected: // Constructors
      ASTLoop() = default;
      ASTLoop(CondNode cond, ASTInnerCode code);
      ASTLoop(const ASTLoop& cp) = default;
      ASTLoop(ASTLoop&& mv) noexcept = default;

  public: // Destructor
      virtual ~ASTLoop() = default;

  public: // Operators
      ASTLoop& operator=(const ASTLoop& cp) = default;
      ASTLoop& operator=(ASTLoop&& mv) noexcept = default;

  private: // Fields
      CondNode cond;
      ASTInnerCode code;
  private: // Methods
  };

  inline const CondNode& ASTLoop::getCond() const {
      return cond;
  }

  inline const ASTInnerCode& ASTLoop::getCode() const {
      return code;
  }

  ASTLoop::ASTLoop(CondNode cond, ASTInnerCode code)
          : cond(std::move(cond)), code(std::move(code)) {}
}

//
// Created by bodand on 2019-07-01.
//

#pragma once

#include <initializer_list>
#include "AstNode.hpp"
#include "codepart/AstCodePart.hpp"
#include "Utils.hpp"
#include "Visitor.hpp"

namespace LibStarch {
  using Utils::Ptr;
  using Utils::mkPtr;

  class ASTInnerCode : public ASTNode {
      class Buidler;
      /// Interface
  public:
      void accept(Visiting::Visitor& visitor) override;
      [[nodiscard]] std::vector<Ptr<ASTCodePart>>& getParts();
      [[nodiscard]] const std::vector<Ptr<ASTCodePart>>& getParts() const;

      /// Lifecycle
  public:
      ASTInnerCode() = default;
      ASTInnerCode(std::initializer_list<Ptr<LibStarch::ASTCodePart>> parts);
      ASTInnerCode(std::vector<Ptr<ASTCodePart>> parts);

      /// Fields
  private:
      std::vector<Ptr<ASTCodePart>> parts;

      /// Internals
  private:
      class Builder {
          /// Interface
      public:
          [[nodiscard]] ASTInnerCode build() const;

          [[nodiscard]] ASTInnerCode operator()() const { return build(); }

          Builder& addPart(Ptr<LibStarch::ASTCodePart>&& part);

          /// Fields
      private:
          std::vector<Ptr<LibStarch::ASTCodePart>> codes;
      };
  };
}

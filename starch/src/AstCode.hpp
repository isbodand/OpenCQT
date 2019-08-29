//
// Created by bodand on 2019-07-01.
//

#pragma once

#include <initializer_list>
#include "AstNode.hpp"
#include "codepart/AstExtendedCodePart.hpp"
#include "Utils.hpp"

namespace LibStarch {
  using Utils::Ptr;
  using Utils::mkPtr;

  class ASTCode : public ASTNode {
      class Builder;

      /// Interface
  public:
      void accept(Visiting::Visitor& visitor) override;
      [[nodiscard]] std::vector<Ptr<ASTExtendedCodePart>>& getParts();
      [[nodiscard]] const std::vector<Ptr<ASTExtendedCodePart>>& getParts() const;

      static Builder getBuilder();

      /// Lifecycle
  public:
      ASTCode() = default;
      ASTCode(std::initializer_list<Ptr<LibStarch::ASTExtendedCodePart>> parts);
      ASTCode(std::vector<Ptr<LibStarch::ASTExtendedCodePart>> parts);

      /// Fields
  private:
      std::vector<Ptr<ASTExtendedCodePart>> parts;

      /// Internals
  private:
      class Builder {
          /// Interface
      public:
          [[nodiscard]] ASTCode build() const;

          [[nodiscard]] ASTCode operator()() const { return build(); }

          Builder& addPart(Ptr<LibStarch::ASTExtendedCodePart>&& part);

          /// Fields
      private:
          std::vector<Ptr<LibStarch::ASTExtendedCodePart>> codes;
      };
  };
}

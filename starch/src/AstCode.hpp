//
// Created by bodand on 2019-07-01.
//

#pragma once

#include <type_traits>
#include <initializer_list>
#include "AstNode.hpp"
#include "Utils.hpp"

namespace LibStarch {
  using Utils::Ptr;
  using Utils::mkPtr;

  class ASTCode : public ASTNode {
      class Builder;

      /// Interface
  public:
      void accept(Visiting::Visitor& visitor) override;
      [[nodiscard]] std::vector<Ptr<ASTCodePart>>& getParts();
      [[nodiscard]] const std::vector<Ptr<ASTCodePart>>& getParts() const;

      static Builder getBuilder();

      /// Lifecycle
  public:
      ASTCode() = default;
      template<
           class CodeType,
           typename = std::enable_if_t<
                std::is_base_of_v<LibStarch::ASTCodePart, CodeType>
           >
      >
      ASTCode(std::initializer_list<Ptr<CodeType>> parts);
      template<
           class CodeType,
           typename = std::enable_if_t<
                std::is_base_of_v<LibStarch::ASTCodePart, CodeType>
           >
      >
      ASTCode(std::vector<Ptr<CodeType>> parts);

      /// Fields
  private:
      std::vector<Ptr<ASTCodePart>> parts;

      /// Internals
  private:
      class Builder {
          /// Interface
      public:
          [[nodiscard]] ASTCode build() const;

          [[nodiscard]] ASTCode operator()() const { return build(); }

          Builder& addPart(Ptr<LibStarch::ASTCodePart>&& part);

          /// Fields
      private:
          std::vector<Ptr<LibStarch::ASTCodePart>> codes;
      };
  };
}

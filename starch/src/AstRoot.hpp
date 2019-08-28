//
// Created by bodand on 2019-07-01.
//

#pragma once

#include <optional>
#include "AstNode.hpp"
#include "AstCode.hpp"

namespace LibStarch {
  class ASTRoot : public ASTNode {
      class Builder;

  public: // Methods
      void accept(Visiting::Visitor& visitor) override;

      ASTCode& getCode();
      [[nodiscard]]static Builder getBuilder();

  public: // Constructors & Destructor
      ASTRoot() = default;
      ASTRoot(ASTCode code);
      ASTRoot(const ASTRoot& cp) = default;
      ASTRoot(ASTRoot&& mv) noexcept = default;

      ~ASTRoot() override = default;

  public: // Operators
      ASTRoot& operator=(const ASTRoot& cp) = default;
      ASTRoot& operator=(ASTRoot&& mv) noexcept = default;

  private: // Fields
      ASTCode code;

  private: // Methods and whatnot
      class Builder {
          /// Interface
      public:
          [[nodiscard]] ASTRoot build() const;
          [[nodiscard]] ASTRoot operator()() const;

          Builder& withCode(ASTCode&& in_code);

          /// Fields
      private:
          std::optional<ASTCode> code;
      };
  };
}

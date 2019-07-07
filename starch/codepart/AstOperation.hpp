//
// Created by bodand on 2019-07-01.
//

#pragma once

#include <optional>
#include "AstCodePart.hpp"
#include "../Utils.hpp"
#include "AstExtendedCodePart.hpp"

namespace LibStarch {
  using Utils::Ptr;
  using Utils::Instruction;
  using Utils::TypeCtor;

  class ASTOperation : public ASTCodePart,
                       public ASTExtendedCodePart {
      /// Interface
  public:
      Instruction getInstr() const;
      const ValNode& getRep() const;
      ValNode& getRep();
      const std::optional<TypeCtor>& getCtor() const;
      void accept(Visiting::Visitor& visitor) override;

      /// Constructors
  public:
      ASTOperation() = default;
      ASTOperation(Instruction instr, Ptr<ValNode> rep, const std::optional<TypeCtor>& ctor);
      ASTOperation(const ASTOperation& cp) = delete;
      ASTOperation(ASTOperation&& mv) noexcept = default;

      /// Destructor
  public:
      virtual ~ASTOperation() = default;

      /// Operators
  public:
      ASTOperation& operator=(const ASTOperation& cp) = delete;
      ASTOperation& operator=(ASTOperation&& mv) noexcept = default;

      /// Fields
  private:
      Instruction instr = (Instruction) 0;
      Ptr<ValNode> rep;
      std::optional<TypeCtor> ctor;

      /// Private Methods
  private:
  };
}

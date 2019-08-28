//
// Created by bodand on 2019-07-01.
//

#pragma once

#include <optional>
#include "AstCodePart.hpp"
#include "../Utils.hpp"
#include "AstExtendedCodePart.hpp"
#include "../val_subtrees/ValId.hpp"
#include "../val_subtrees/ValNumber.hpp"

namespace LibStarch {
  using Utils::Ptr;
  using Utils::mkPtr;
  using Utils::Instruction;
  using Utils::TypeCtor;

  class ASTOperation : public ASTCodePart,
                       public ASTExtendedCodePart {
      /// Interface
  public:
      [[nodiscard]] Instruction getInstr() const;
      [[nodiscard]] const ValNode& getRep() const;
      [[nodiscard]] ValNode& getRep();
      [[nodiscard]] const std::optional<TypeCtor>& getCtor() const;
      [[nodiscard]] const std::optional<ValID>& getInvId() const;
      [[nodiscard]] std::optional<ValID>& getInvId();
      [[nodiscard]] const std::vector<std::string>& getArgs() const;
      void accept(Visiting::Visitor& visitor) override;

      /// Constructors
  public:
      ASTOperation() = default;
      ASTOperation(Instruction instr, Ptr<ValNode> rep = mkPtr<ValNumber>(1),
                   std::optional<TypeCtor> ctor = std::nullopt);
      ASTOperation(ValID id, std::vector<std::string> args);
      ASTOperation(const ASTOperation& cp) = delete;
      ASTOperation(ASTOperation&& mv) noexcept = default;

      /// Destructor
  public:
      ~ASTOperation() override = default;

      /// Operators
  public:
      ASTOperation& operator=(const ASTOperation& cp) = delete;
      ASTOperation& operator=(ASTOperation&& mv) noexcept = default;

      /// Fields
  private:
      Instruction instr = (Instruction) 0;
      Ptr<ValNode> rep;
      std::optional<TypeCtor> ctor;
      std::optional<ValID> invId;
      std::vector<std::string> args;
  };
}

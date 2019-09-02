//
// Created by bodand on 2019-07-01.
//

#pragma once

#include <optional>
#include <utility>
#include "AstCodePart.hpp"
#include "../Utils.hpp"
#include "../val_subtrees/ValId.hpp"
#include "../val_subtrees/ValNumber.hpp"

namespace LibStarch {
  using Utils::Ptr;
  using Utils::mkPtr;
  using Utils::Instruction;
  using Utils::TypeCtor;

  class ASTOperation : public ASTRestrictedCodePart {
      class Builder;
      /// Interface
  public:
      [[nodiscard]] Instruction getInstr() const;
      [[nodiscard]] const ValNode& getRep() const;
      [[nodiscard]] ValNode& getRep();
      [[nodiscard]] const std::optional<TypeCtor>& getCtor() const;
      [[nodiscard]] std::optional<TypeCtor>& getCtor();
      [[nodiscard]] const std::optional<ValID>& getInvId() const;
      [[nodiscard]] std::optional<ValID>& getInvId();
      [[nodiscard]] const std::vector<std::string>& getArgs() const;
      void accept(Visiting::Visitor& visitor) override;

      static Builder getBuilder();

      /// Constructors
  public:
      ASTOperation() = default;
      ASTOperation(Instruction instr, Ptr<ValNode> rep = ValNode::mkPtrNumber(1),
                   std::optional<TypeCtor> ctor = std::nullopt);
      ASTOperation(ValID id, std::vector<std::string> args);
      ASTOperation(const ASTOperation& cp) = default;
      ASTOperation(ASTOperation&& mv) noexcept = default;

      /// Destructor
  public:
      ~ASTOperation() override = default;

      /// Operators
  public:
      ASTOperation& operator=(const ASTOperation& cp) = delete;
      ASTOperation& operator=(ASTOperation&& mv) noexcept = default;

      [[nodiscard]] explicit operator std::shared_ptr<ASTOperation>() const {
          return std::make_shared<ASTOperation>(*this);// Copy that shit
      }

      /// Fields
  private:
      Instruction instr;
      Ptr<ValNode> rep;
      std::optional<TypeCtor> ctor;
      std::optional<ValID> invId;
      std::vector<std::string> args;

      /// Internals
      class Builder {
          class InstrBuilder;

          class CallBuilder;

          /// Interface
      public:
          InstrBuilder asInstruction(Instruction instr);
          CallBuilder asFunctionCall(ValID id);

          /// Internals
      private:
          class InstrBuilder {
              /// Interface
          public:
              [[nodiscard]] ASTOperation build() const;
              [[nodiscard]] Ptr<ASTOperation> buildPtr() const;

              /// Lifecycle
          public:
              InstrBuilder(Instruction instr);

              InstrBuilder& withRepetition(Ptr<ValNode> val);
              InstrBuilder& withRepetition(ValNode* val);
              InstrBuilder& withConstructor(TypeCtor ctor);
              InstrBuilder& withConstructor(Utils::Type type, ValNode* val);

              /// Fields
          private:
              Instruction instr;
              Ptr<ValNode> rep = ValNode::mkPtrNumber(1);
              std::optional<TypeCtor> _ctor = std::nullopt;
          };

          class CallBuilder {
              /// Interface
          public:
              [[nodiscard]] ASTOperation build() const;

              CallBuilder& addArgument(const std::string& arg);

              /// Lifecycle
          public:
              CallBuilder(ValID id);

              /// Fields
          private:
              ValID id;
              std::vector<std::string> args;
          };
      };
  };

}

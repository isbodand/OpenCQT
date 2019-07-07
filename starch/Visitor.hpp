//
// Created by tudom on 2019-05-29.
//

#pragma once

namespace LibStarch {
  //&!off
  class ASTRoot;
  // Codes
  class ASTCodePart;
  class ASTInnerCode;

  class ASTExtendedCodePart;
  class ASTCode;

  // Loops
  class ASTForLoop;
  class ASTDoLoop;
  class ASTWhileLoop;

  // Ops
  class ASTOperation;

  // Expr
  class CExpression;

  // Values
  class ValExpr;
  class ValText;
  class ValNumber;
  class ValID;
  //&!on

  namespace Visiting {

    class Visitor {
    public: // Methods
        virtual void visit(ASTRoot& root) = 0;
        virtual void visit(ASTInnerCode& icode) = 0;
        virtual void visit(ASTCode& code) = 0;
        virtual void visit(ASTForLoop& for_) = 0;
        virtual void visit(ASTWhileLoop& while_) = 0;
        virtual void visit(ASTDoLoop& do_) = 0;
        virtual void visit(ASTOperation& op) = 0;
        virtual void visit(ValExpr& expr) = 0;
        virtual void visit(ValText& txt) = 0;
        virtual void visit(ValNumber& num) = 0;
        virtual void visit(ValID& id) = 0;


    public: // Constructors & Destructor
        Visitor() = default;
        Visitor(const Visitor& cp) = default;
        Visitor(Visitor&& mv) noexcept = default;

        virtual ~Visitor() = default;

    public: // Operators
        Visitor& operator=(const Visitor& cp) = default;
        Visitor& operator=(Visitor&& mv) noexcept = default;
    };
  }
}

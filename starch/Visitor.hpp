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
  class AdditionExpression;
  class SubtractionExpression;
  class MultiplicationExpression;
  class DivisionExpression;
  class ModuloExpression;

  class ValueExpression;
  class NegateExpression;

  class TernaryExpression;

  class EqualityExpression;
  class InequalityExpression;
  class GreaterThanExpression;
  class GreaterOrEqualExpression;
  class LessThanExpression;
  class LessOrEqualExpression;

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

        virtual void visit(AdditionExpression& expr) = 0;
        virtual void visit(SubtractionExpression& expr) = 0;
        virtual void visit(MultiplicationExpression& expr) = 0;
        virtual void visit(DivisionExpression& expr) = 0;
        virtual void visit(ModuloExpression& expr) = 0;

        virtual void visit(ValueExpression& expr) = 0;
        virtual void visit(NegateExpression& expr) = 0;

        virtual void visit(TernaryExpression& expr) = 0;

        virtual void visit(EqualityExpression& expr) = 0;
        virtual void visit(InequalityExpression& expr) = 0;
        virtual void visit(GreaterThanExpression& expr) = 0;
        virtual void visit(GreaterOrEqualExpression& expr) = 0;
        virtual void visit(LessThanExpression& expr) = 0;
        virtual void visit(LessOrEqualExpression& expr) = 0;

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

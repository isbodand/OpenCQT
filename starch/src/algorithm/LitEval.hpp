//
// Created by bodand on 2019-08-21.
//

#pragma once

#include "../Visitor.hpp"

namespace LibStarch::Algorithm {
  class LitEval : public ::LibStarch::Visiting::Visitor {
      /// Interface
  public:
      void visit(ASTRoot& root) override;
      void visit(ASTCode& code) override;
      void visit(ASTInnerCode& icode) override;
      void visit(ASTOperation& op) override;
      void visit(ValExpr& expr) override;
      void visit(ValText& txt) override;
      void visit(ValNumber& num) override;
      void visit(ValID& id) override;
      void visit(ASTForLoop& for_) override;
      void visit(ASTWhileLoop& while_) override;
      void visit(ASTDoLoop& do_) override;
      void visit(AdditionExpression& expr) override;
      void visit(SubtractionExpression& expr) override;
      void visit(MultiplicationExpression& expr) override;
      void visit(DivisionExpression& expr) override;
      void visit(ModuloExpression& expr) override;
      void visit(ValueExpression& expr) override;
      void visit(NegateExpression& expr) override;
      void visit(TernaryExpression& expr) override;
      void visit(EqualityExpression& expr) override;
      void visit(InequalityExpression& expr) override;
      void visit(GreaterThanExpression& expr) override;
      void visit(GreaterOrEqualExpression& expr) override;
      void visit(LessThanExpression& expr) override;
      void visit(LessOrEqualExpression& expr) override;

      /// Fields
  private:

      /// Methods
  private:
  };
}

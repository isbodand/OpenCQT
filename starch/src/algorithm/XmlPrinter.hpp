//
// Created by bodand on 2019-07-01.
//

#pragma once

#include <string>

#include <tinyxml2.h>

#include "../Visitor.hpp"
#include "../AstRoot.hpp"
#include "../cexpr/CExpression.hpp"

namespace LibStarch::Algorithm {
  namespace xml = tinyxml2;

  class XMLPrinter : public ::LibStarch::Visiting::Visitor {
      /// Interface8
  public:
      [[nodiscard]] std::string getXml() const;

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
      void visit(ASTMacroDefinition macro) override;
      void visit(ASTSubDefinition sub) override;
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

      /// Operators
  public:
      operator bool();

      /// Fields
  private:
      xml::XMLDocument doc;
      xml::XMLNode* lastElem;
      bool set = false;

      /// Methods
  private:
      void valInserter(const std::string& type, const ValNode& val);
      void exprInserter(const LibStarch::CExpression& expr, const std::string& exprName);
  };
}

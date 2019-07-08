//
// Created by bodand on 2019-07-01.
//

#pragma once

#include <string>
#include "../Visitor.hpp"
#include "../AstRoot.hpp"

namespace LibStarch::Algorithm {
  class XMLPrinter : public ::LibStarch::Visiting::Visitor {
      using XmlType = std::string;
      using XmlIterator = XmlType::iterator;

      /// Interface
  public:
      const std::string& getXml() const;

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

      /// Constructors & Destructor
  public:
      XMLPrinter() = default;
      XMLPrinter(const XMLPrinter& cp) = default;
      XMLPrinter(XMLPrinter&& mv) noexcept = default;

      virtual ~XMLPrinter() = default;

      /// Operators
  public:
      XMLPrinter& operator=(const XMLPrinter& cp) = default;
      XMLPrinter& operator=(XMLPrinter&& mv) noexcept = default;
      operator bool();

      /// Fields
  private:
      XmlType Xml = R"(<?xml version="1.0" encoding="UTF-8" ?>)" "\n";
      XmlIterator insertPos = Xml.begin() + Xml.length();
      int tab = 0;

      /// Methods
  private:
      void valInserter(const std::string& type, const ValNode& val);
      void insert(std::string& toInsert, unsigned long long int followUpInserPos);
      std::string mkTags(const std::string& tag, std::string& start, std::string& fin);
      std::string mkTags(const std::string& tags, const std::string& tagf, std::string& start, std::string& fin);
  };
}

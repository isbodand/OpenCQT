//
// Created by bodand on 2019-06-29.
//

#pragma once

#include <ostream>
#include <iostream>
#include <sstream>
#include "../cexpr/CExpression.hpp"
#include "ValNode.hpp"
#include "../Utils.hpp"

namespace LibStarch {
  using Utils::mkPtr;
  using Utils::Ptr;

  class ValExpr : public ValNode {
  public: // Methods
      double eval() const override;
      void asString(std::ostream& os) const override;
      void accept(Visiting::Visitor& visitor) override;
      Utils::ExprType getTyp() const;
      const Ptr<LibStarch::CExpression>& getExpr() const;

  public: // Constructors & Destructor
      template<class Expr>
      ValExpr(Expr* expr);
      ValExpr(const ValExpr& cp) = default;
      ValExpr(ValExpr&& mv) noexcept = default;

      virtual ~ValExpr() = default;

  public: // Operators
      ValExpr& operator=(const ValExpr& cp) = default;
      ValExpr& operator=(ValExpr&& mv) noexcept = default;

  private: // Fields
      Ptr<CExpression> expr;
      Utils::ExprType typ;

  private: // Methods
      ValExpr() = default;
  };

  template<class Expr>
  inline ValExpr::ValExpr(Expr* expr)
          : expr(expr) {
      using namespace Utils;
      std::string type(std::to_string(*expr));
      if (type == "AdditionExpression") {
          typ = Impl::exprAddition;
      } else if (type == "SubtractionExpression") {
          typ = Impl::exprSubtraction;
      } else if (type == "MultiplicationExpression") {
          typ = Impl::exprMultiplication;
      } else if (type == "DivisionExpression") {
          typ = Impl::exprDivision;
      } else if (type == "ModuloExpression") {
          typ = Impl::exprModulo;
      } else if (type == "ValueExpression") {
          typ = Impl::exprValue;
      } else if (type == "NegateExpression") {
          typ = Impl::exprNegate;
      } else if (type == "TernaryExpression") {
          typ = Impl::exprTernary;
      } else if (type == "EqualityExpression") {
          typ = Impl::exprEquality;
      } else if (type == "InequalityExpression") {
          typ = Impl::exprInequality;
      } else if (type == "GreaterThanExpression") {
          typ = Impl::exprGreaterThan;
      } else if (type == "GreaterOrEqualExpression") {
          typ = Impl::exprGreaterOrEqual;
      } else if (type == "LessThanExpression") {
          typ = Impl::exprLessThan;
      } else if (type == "LessOrEqualExpression") {
          typ = Impl::exprLessOrEqual;
      } else {
          typ = Impl::exprValue;
      }
  }
}

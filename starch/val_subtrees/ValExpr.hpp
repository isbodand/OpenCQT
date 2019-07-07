//
// Created by bodand on 2019-06-29.
//

#pragma once

#ifdef __GNUG__
#define Unused [[gnu::unused]]
#else
  #defin Unused
#endif

#include <ostream>
#include <iostream>
#include <sstream>
#include "../cexpr/CExpression.hpp"
#include "ValNode.hpp"
#include "../Utils.hpp"

namespace LibStarch {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"

  using Utils::mkPtr;
  using Utils::Ptr;

  class ValExpr : public ValNode {
  public: // Methods
      double eval() const override;
      void asString(std::ostream& os) const override;
      void accept(Visiting::Visitor& visitor) override;

  public: // Constructors & Destructor
      template<class Expr>
      ValExpr(Expr expr, Unused void*);
      ValExpr(const ValExpr& cp) = default;
      ValExpr(ValExpr&& mv) noexcept = default;

      virtual ~ValExpr() = default;

  public: // Operators
      ValExpr& operator=(const ValExpr& cp) = default;
      ValExpr& operator=(ValExpr&& mv) noexcept = default;

  private: // Fields
      Ptr<CExpression> expr;

  private: // Methods
      ValExpr() = default;
  };

#pragma clang diagnostic pop

  inline double LibStarch::ValExpr::eval() const {
      return expr->eval();
  }

  inline void ValExpr::asString(std::ostream& os) const {
      os << "[ValExpr(" << expr->eval() << "): "
         << *expr
         << "]";
  }

  inline void ValExpr::accept(Visiting::Visitor& visitor) {
      visitor.visit(*this);
  }

  template<class Expr>
  inline ValExpr::ValExpr(Expr expr, Unused void*) //&!off
          : expr(std::make_shared<Expr>(std::move(expr))) {}
  //&!on

}

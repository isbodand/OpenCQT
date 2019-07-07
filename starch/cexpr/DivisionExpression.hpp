//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "impl/CExpressionImpl.hpp"

namespace LibStarch {
  template<class L, class R>
  class DivisionExpression : public CExpressionImpl<L, R> {
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      DivisionExpression() = delete;
      DivisionExpression(const L& lhs, const R& rhs);
      DivisionExpression(const DivisionExpression& cp) = default;
      DivisionExpression(DivisionExpression&& mv) noexcept = default;

      virtual ~DivisionExpression() = default;

  public: // Operators
      DivisionExpression& operator=(const DivisionExpression& cp) = default;
      DivisionExpression& operator=(DivisionExpression&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline double DivisionExpression<L, R>::eval() const {
      return this->left() / this->right();
  }

  template<class L, class R>
  inline std::string DivisionExpression<L, R>::getPrintName() const {
      return "Div";
  }

  template<class L, class R>
  inline DivisionExpression<L, R>::DivisionExpression(const L& lhs, const R& rhs)
          :CExpressionImpl<L, R>(lhs, rhs, std::nullopt) {}
}

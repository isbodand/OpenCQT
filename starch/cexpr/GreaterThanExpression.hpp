//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "impl/CExpressionImpl.hpp"

namespace LibStarch {
  template<class L, class R>
  class GreaterThanExpression : public CExpressionImpl<L, R> {
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      GreaterThanExpression() = delete;
      GreaterThanExpression(const L& lhs, const R& rhs);
      GreaterThanExpression(const GreaterThanExpression& cp) = default;
      GreaterThanExpression(GreaterThanExpression&& mv) noexcept = default;

      virtual ~GreaterThanExpression() = default;

  public: // Operators
      GreaterThanExpression& operator=(const GreaterThanExpression& cp) = default;
      GreaterThanExpression& operator=(GreaterThanExpression&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline GreaterThanExpression<L, R>::GreaterThanExpression(const L& lhs, const R& rhs)
          : CExpressionImpl<L, R>(lhs, rhs) {}

  template<class L, class R>
  inline double GreaterThanExpression<L, R>::eval() const {
      return Utils::dgt(this->left(), this->right());
  }

  template<class L, class R>
  inline std::string GreaterThanExpression<L, R>::getPrintName() const {
      return "Gt";
  }

}

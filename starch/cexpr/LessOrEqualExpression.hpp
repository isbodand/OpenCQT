//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "impl/CExpressionImpl.hpp"

namespace LibStarch {
  template<class L, class R>
  class LessOrEqualExpression : public CExpressionImpl<L, R> {
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      LessOrEqualExpression() = delete;
      LessOrEqualExpression(const L& lhs, const R& rhs);
      LessOrEqualExpression(const LessOrEqualExpression& cp) = default;
      LessOrEqualExpression(LessOrEqualExpression&& mv) noexcept = default;

      virtual ~LessOrEqualExpression() = default;

  public: // Operators
      LessOrEqualExpression& operator=(const LessOrEqualExpression& cp) = default;
      LessOrEqualExpression& operator=(LessOrEqualExpression&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline double LessOrEqualExpression<L, R>::eval() const {
      return Utils::dle(this->left(), this->right());
  }

  template<class L, class R>
  inline std::string LessOrEqualExpression<L, R>::getPrintName() const {
      return "Le";
  }

  template<class L, class R>
  LessOrEqualExpression<L, R>::LessOrEqualExpression(const L& lhs, const R& rhs)
          : CExpressionImpl<L, R>(lhs, rhs) {}
}

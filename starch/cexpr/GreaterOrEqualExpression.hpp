//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "impl/CExpressionImpl.hpp"

namespace LibStarch {
  template<class L, class R>
  class GreaterOrEqualExpression : public CExpressionImpl<L, R> {
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      GreaterOrEqualExpression() = delete;
      GreaterOrEqualExpression(const L& lhs, const R& rhs);
      GreaterOrEqualExpression(const GreaterOrEqualExpression& cp) = default;
      GreaterOrEqualExpression(GreaterOrEqualExpression&& mv) noexcept = default;

      virtual ~GreaterOrEqualExpression() = default;

  public: // Operators
      GreaterOrEqualExpression& operator=(const GreaterOrEqualExpression& cp) = default;
      GreaterOrEqualExpression& operator=(GreaterOrEqualExpression&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline std::string GreaterOrEqualExpression<L, R>::getPrintName() const {
      return "Ge";
  }

  template<class L, class R>
  inline double GreaterOrEqualExpression<L, R>::eval() const {
      return Utils::dge(this->left(), this->right());
  }

  template<class L, class R>
  GreaterOrEqualExpression<L, R>::GreaterOrEqualExpression(const L& lhs, const R& rhs)
          : CExpressionImpl<L, R>(lhs, rhs) {}
}

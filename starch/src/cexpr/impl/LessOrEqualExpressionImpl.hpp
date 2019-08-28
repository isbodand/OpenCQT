//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "CExpressionImpl.hpp"
#include "../LessOrEqualExpression.hpp"

namespace LibStarch {
  template<class L, class R>
  class LessOrEqualExpressionImpl : public LessOrEqualExpression,
                                    public CExpressionImpl<L, R> {
      using ImplOf = LessOrEqualExpression;
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      LessOrEqualExpressionImpl() = delete;
      LessOrEqualExpressionImpl(const L& lhs, const R& rhs);
      LessOrEqualExpressionImpl(const LessOrEqualExpressionImpl& cp) = default;
      LessOrEqualExpressionImpl(LessOrEqualExpressionImpl&& mv) noexcept = default;

      virtual ~LessOrEqualExpressionImpl() = default;

  public: // Operators
      LessOrEqualExpressionImpl& operator=(const LessOrEqualExpressionImpl& cp) = default;
      LessOrEqualExpressionImpl& operator=(LessOrEqualExpressionImpl&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline double LessOrEqualExpressionImpl<L, R>::eval() const {
      return Utils::dle(this->left(), this->right());
  }

  template<class L, class R>
  inline std::string LessOrEqualExpressionImpl<L, R>::getPrintName() const {
      return "Le";
  }

  template<class L, class R>
  LessOrEqualExpressionImpl<L, R>::LessOrEqualExpressionImpl(const L& lhs, const R& rhs)
          : CExpressionImpl<L, R>(lhs, rhs) {}
}

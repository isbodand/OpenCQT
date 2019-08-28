//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "CExpressionImpl.hpp"
#include "../GreaterOrEqualExpression.hpp"

namespace LibStarch {
  template<class L, class R>
  class GreaterOrEqualExpressionImpl : public GreaterOrEqualExpression,
                                       public CExpressionImpl<L, R> {
      using ImplOf = GreaterOrEqualExpression;
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      GreaterOrEqualExpressionImpl() = delete;
      GreaterOrEqualExpressionImpl(const L& lhs, const R& rhs);
      GreaterOrEqualExpressionImpl(const GreaterOrEqualExpressionImpl& cp) = default;
      GreaterOrEqualExpressionImpl(GreaterOrEqualExpressionImpl&& mv) noexcept = default;

      virtual ~GreaterOrEqualExpressionImpl() = default;

  public: // Operators
      GreaterOrEqualExpressionImpl& operator=(const GreaterOrEqualExpressionImpl& cp) = default;
      GreaterOrEqualExpressionImpl& operator=(GreaterOrEqualExpressionImpl&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline std::string GreaterOrEqualExpressionImpl<L, R>::getPrintName() const {
      return "Ge";
  }

  template<class L, class R>
  inline double GreaterOrEqualExpressionImpl<L, R>::eval() const {
      return Utils::dge(this->left(), this->right());
  }

  template<class L, class R>
  GreaterOrEqualExpressionImpl<L, R>::GreaterOrEqualExpressionImpl(const L& lhs, const R& rhs)
          : CExpressionImpl<L, R>(lhs, rhs) {}
}

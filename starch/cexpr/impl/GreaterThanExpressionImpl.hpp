//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "CExpressionImpl.hpp"
#include "../GreaterThanExpression.hpp"

namespace LibStarch {
  template<class L, class R>
  class GreaterThanExpressionImpl : public GreaterThanExpression,
                                    public CExpressionImpl<L, R> {
      using ImplOf = GreaterThanExpression;
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      GreaterThanExpressionImpl() = delete;
      GreaterThanExpressionImpl(const L& lhs, const R& rhs);
      GreaterThanExpressionImpl(const GreaterThanExpressionImpl& cp) = default;
      GreaterThanExpressionImpl(GreaterThanExpressionImpl&& mv) noexcept = default;

      virtual ~GreaterThanExpressionImpl() = default;

  public: // Operators
      GreaterThanExpressionImpl& operator=(const GreaterThanExpressionImpl& cp) = default;
      GreaterThanExpressionImpl& operator=(GreaterThanExpressionImpl&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline GreaterThanExpressionImpl<L, R>::GreaterThanExpressionImpl(const L& lhs, const R& rhs)
          : CExpressionImpl<L, R>(lhs, rhs) {}

  template<class L, class R>
  inline double GreaterThanExpressionImpl<L, R>::eval() const {
      return Utils::dgt(this->left(), this->right());
  }

  template<class L, class R>
  inline std::string GreaterThanExpressionImpl<L, R>::getPrintName() const {
      return "Gt";
  }

}

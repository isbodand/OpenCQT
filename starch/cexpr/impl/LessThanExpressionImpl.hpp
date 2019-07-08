//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "CExpressionImpl.hpp"
#include "../LessThanExpression.hpp"

namespace LibStarch {
  template<class L, class R>
  class LessThanExpressionImpl : public LessThanExpression,
                                 public CExpressionImpl<L, R> {
      using ImplOf = LessThanExpression;
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      LessThanExpressionImpl() = delete;
      LessThanExpressionImpl(const L& lhs, const R& rhs);
      LessThanExpressionImpl(const LessThanExpressionImpl& cp) = default;
      LessThanExpressionImpl(LessThanExpressionImpl&& mv) noexcept = default;

      virtual ~LessThanExpressionImpl() = default;

  public: // Operators
      LessThanExpressionImpl& operator=(const LessThanExpressionImpl& cp) = default;
      LessThanExpressionImpl& operator=(LessThanExpressionImpl&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline LessThanExpressionImpl<L, R>::LessThanExpressionImpl(const L& lhs, const R& rhs)
          : CExpressionImpl<L, R>(lhs, rhs) {}

  template<class L, class R>
  inline double LessThanExpressionImpl<L, R>::eval() const {
      return Utils::dlt(this->left(), this->right());
  }

  template<class L, class R>
  inline std::string LessThanExpressionImpl<L, R>::getPrintName() const {
      return "Lt";
  }
}

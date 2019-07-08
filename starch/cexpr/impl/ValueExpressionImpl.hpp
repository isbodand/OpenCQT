//
// Created by bodand on 2019-06-30.
//

#pragma once

#include <ostream>

#include "CExpressionImpl.hpp"
#include "../ValueExpression.hpp"

namespace LibStarch {
  template<class L, class R = int>
  class ValueExpressionImpl : public ValueExpression,
                              public CExpressionImpl<L, R> {
      using ImplOf = ValueExpression;
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      ValueExpressionImpl() = delete;
      ValueExpressionImpl(const L& lhs);
      ValueExpressionImpl(const ValueExpressionImpl& cp) = default;
      ValueExpressionImpl(ValueExpressionImpl&& mv) noexcept = default;

      virtual ~ValueExpressionImpl() = default;

  public: // Operators
      ValueExpressionImpl& operator=(const ValueExpressionImpl& cp) = default;
      ValueExpressionImpl& operator=(ValueExpressionImpl&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline ValueExpressionImpl<L, R>::ValueExpressionImpl(const L& lhs)
          : CExpressionImpl<L, R>(lhs) {}

  template<class L, class R>
  inline double ValueExpressionImpl<L, R>::eval() const {
      return this->left();
  }

  template<class L, class R>
  inline std::string ValueExpressionImpl<L, R>::getPrintName() const {
      return "Value";
  }
}

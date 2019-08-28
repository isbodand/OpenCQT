//
// Created by bodand on 2019-06-30.
//

#pragma once

#include <ostream>

#include "CExpressionImpl.hpp"
#include "../ValueExpression.hpp"

namespace LibStarch {
  template<class L>
  class ValueExpressionImpl : public ValueExpression,
                              public CExpressionImpl<L, int> {
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

  template<class L>
  inline ValueExpressionImpl<L>::ValueExpressionImpl(const L& lhs)
       : CExpressionImpl<L, int>(lhs) {}

  template<class L>
  inline double ValueExpressionImpl<L>::eval() const {
      return this->left();
  }

  template<class L>
  inline std::string ValueExpressionImpl<L>::getPrintName() const {
      return "Value";
  }
}

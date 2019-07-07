//
// Created by bodand on 2019-06-30.
//

#pragma once

#include <ostream>
#include "impl/CExpressionImpl.hpp"

namespace LibStarch {
  template<class L, class R = int>
  class ValueExpression : public CExpressionImpl<L, R> {
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      ValueExpression() = delete;
      ValueExpression(const L& lhs);
      ValueExpression(const ValueExpression& cp) = default;
      ValueExpression(ValueExpression&& mv) noexcept = default;

      virtual ~ValueExpression() = default;

  public: // Operators
      ValueExpression& operator=(const ValueExpression& cp) = default;
      ValueExpression& operator=(ValueExpression&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline ValueExpression<L, R>::ValueExpression(const L& lhs)
          : CExpressionImpl<L, R>(lhs) {}

  template<class L, class R>
  inline double ValueExpression<L, R>::eval() const {
      return this->left();
  }

  template<class L, class R>
  inline std::string ValueExpression<L, R>::getPrintName() const {
      return "Value";
  }
}

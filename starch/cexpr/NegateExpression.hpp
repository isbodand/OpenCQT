//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "impl/CExpressionImpl.hpp"

namespace LibStarch {
  template<class L, class R = int>
  class NegateExpression : public CExpressionImpl<L, R> {
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      NegateExpression() = delete;
      NegateExpression(const L& lhs);
      NegateExpression(const NegateExpression& cp) = default;
      NegateExpression(NegateExpression&& mv) noexcept = default;

      virtual ~NegateExpression() = default;

  public: // Operators
      NegateExpression& operator=(const NegateExpression& cp) = default;
      NegateExpression& operator=(NegateExpression&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline NegateExpression<L, R>::NegateExpression(const L& lhs)
          : CExpressionImpl<L, R>(lhs) {}

  template<class L, class R>
  inline std::string NegateExpression<L, R>::getPrintName() const {
      return "Negate";
  }

  template<class L, class R>
  inline double NegateExpression<L, R>::eval() const {
      return -this->left();
  }
}

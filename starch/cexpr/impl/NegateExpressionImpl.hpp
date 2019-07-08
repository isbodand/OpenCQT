//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "CExpressionImpl.hpp"
#include "../NegateExpression.hpp"

namespace LibStarch {
  template<class L, class R = int>
  class NegateExpressionImpl : public NegateExpression,
                               public CExpressionImpl<L, R> {
      using ImplOf = NegateExpression;
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      NegateExpressionImpl() = delete;
      NegateExpressionImpl(const L& lhs);
      NegateExpressionImpl(const NegateExpressionImpl& cp) = default;
      NegateExpressionImpl(NegateExpressionImpl&& mv) noexcept = default;

      virtual ~NegateExpressionImpl() = default;

  public: // Operators
      NegateExpressionImpl& operator=(const NegateExpressionImpl& cp) = default;
      NegateExpressionImpl& operator=(NegateExpressionImpl&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline NegateExpressionImpl<L, R>::NegateExpressionImpl(const L& lhs)
          : CExpressionImpl<L, R>(lhs) {}

  template<class L, class R>
  inline std::string NegateExpressionImpl<L, R>::getPrintName() const {
      return "Negate";
  }

  template<class L, class R>
  inline double NegateExpressionImpl<L, R>::eval() const {
      return -this->left();
  }
}

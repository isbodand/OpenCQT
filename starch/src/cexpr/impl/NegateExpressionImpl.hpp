//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "CExpressionImpl.hpp"
#include "../NegateExpression.hpp"

namespace LibStarch {
  template<class L>
  class NegateExpressionImpl : public NegateExpression,
                               public CExpressionImpl<L, int> {
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

  template<class L>
  inline NegateExpressionImpl<L>::NegateExpressionImpl(const L& lhs)
       : CExpressionImpl<L, int>(lhs) {}

  template<class L>
  inline std::string NegateExpressionImpl<L>::getPrintName() const {
      return "Negate";
  }

  template<class L>
  inline double NegateExpressionImpl<L>::eval() const {
      return -this->left();
  }
}

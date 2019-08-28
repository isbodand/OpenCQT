//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "CExpressionImpl.hpp"
#include "../TernaryExpression.hpp"

namespace LibStarch {
  template<class L, class R>
  class TernaryExpressionImpl : public TernaryExpression,
                                public CExpressionImpl<L, R> {
      using ImplOf = TernaryExpression;
  public: // Methods
      double eval() const override;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      TernaryExpressionImpl() = delete;
      TernaryExpressionImpl(const L& lhs, const R& rhs,
                            const std::optional<CondNode>& cond);
      TernaryExpressionImpl(const TernaryExpressionImpl& cp) = default;
      TernaryExpressionImpl(TernaryExpressionImpl&& mv) noexcept = default;

      virtual ~TernaryExpressionImpl() = default;

  public: // Operators
      TernaryExpressionImpl& operator=(const TernaryExpressionImpl& cp) = default;
      TernaryExpressionImpl& operator=(TernaryExpressionImpl&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline std::string TernaryExpressionImpl<L, R>::getPrintName() const {
      return "Ternary";
  }

  template<class L, class R>
  inline double TernaryExpressionImpl<L, R>::eval() const {
      if (this->cond->eval()) {
          std::cout << "B" << std::endl;
          return this->left();
      }
      return this->right();
  }

  template<class L, class R>
  inline TernaryExpressionImpl<L, R>::TernaryExpressionImpl(const L& lhs, const R& rhs,
                                                            const std::optional<CondNode>& cond)
          : CExpressionImpl<L, R>(lhs, rhs, cond) {}
}

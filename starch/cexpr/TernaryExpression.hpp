//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "impl/CExpressionImpl.hpp"

namespace LibStarch {
  template<class L, class R>
  class TernaryExpression : public CExpressionImpl<L, R> {
  public: // Methods
      double eval() const override;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      TernaryExpression() = delete;
      TernaryExpression(const L& lhs, const R& rhs,
                        const std::optional<CondNode>& cond);
      TernaryExpression(const TernaryExpression& cp) = default;
      TernaryExpression(TernaryExpression&& mv) noexcept = default;

      virtual ~TernaryExpression() = default;

  public: // Operators
      TernaryExpression& operator=(const TernaryExpression& cp) = default;
      TernaryExpression& operator=(TernaryExpression&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline std::string TernaryExpression<L, R>::getPrintName() const {
      return "Ternary";
  }

  template<class L, class R>
  inline double TernaryExpression<L, R>::eval() const {
      if (this->cond->eval()) {
          std::cout << "B" << std::endl;
          return this->left();
      }
      return this->right();
  }

  template<class L, class R>
  inline TernaryExpression<L, R>::TernaryExpression(const L& lhs, const R& rhs,
                                                    const std::optional<CondNode>& cond)
          : CExpressionImpl<L, R>(lhs, rhs, cond) {}
}

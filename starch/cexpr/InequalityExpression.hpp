//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "impl/CExpressionImpl.hpp"

namespace LibStarch {
  template<class L, class R>
  class InequalityExpression : public CExpressionImpl<L, R> {
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      InequalityExpression() = delete;
      InequalityExpression(const L& lhs, const R& rhs);
      InequalityExpression(const InequalityExpression& cp) = default;
      InequalityExpression(InequalityExpression&& mv) noexcept = default;

      virtual ~InequalityExpression() = default;

  public: // Operators
      InequalityExpression& operator=(const InequalityExpression& cp) = default;
      InequalityExpression& operator=(InequalityExpression&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline double InequalityExpression<L, R>::eval() const {
      return Utils::dne(this->left(), this->right());
  }

  template<class L, class R>
  inline std::string InequalityExpression<L, R>::getPrintName() const {
      return "Ne";
  }

  template<class L, class R>
  InequalityExpression<L, R>::InequalityExpression(const L& lhs, const R& rhs)
          : CExpressionImpl<L, R>(lhs, rhs) {}
}


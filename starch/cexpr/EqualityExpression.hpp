//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "impl/CExpressionImpl.hpp"

namespace LibStarch {
  template<class L, class R>
  class EqualityExpression : public CExpressionImpl<L, R> {
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      EqualityExpression() = delete;
      EqualityExpression(const L& lhs, const R& rhs);
      EqualityExpression(const EqualityExpression& cp) = default;
      EqualityExpression(EqualityExpression&& mv) noexcept = default;

      virtual ~EqualityExpression() = default;

  public: // Operators
      EqualityExpression& operator=(const EqualityExpression& cp) = default;
      EqualityExpression& operator=(EqualityExpression&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline double EqualityExpression<L, R>::eval() const {
      return Utils::deq(this->left(), this->right());
  }

  template<class L, class R>
  inline std::string EqualityExpression<L, R>::getPrintName() const {
      return "Eq";
  }

  template<class L, class R>
  inline EqualityExpression<L, R>::EqualityExpression(const L& lhs, const R& rhs)
          : CExpressionImpl<L, R>(lhs, rhs, std::nullopt) {}
}

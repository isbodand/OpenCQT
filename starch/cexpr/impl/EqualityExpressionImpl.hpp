//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "CExpressionImpl.hpp"
#include "../EqualityExpression.hpp"

namespace LibStarch {
  template<class L, class R>
  class EqualityExpressionImpl : public EqualityExpression,
                                 public CExpressionImpl<L, R> {
      using ImplOf = EqualityExpression;
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      EqualityExpressionImpl() = delete;
      EqualityExpressionImpl(const L& lhs, const R& rhs);
      EqualityExpressionImpl(const EqualityExpressionImpl& cp) = default;
      EqualityExpressionImpl(EqualityExpressionImpl&& mv) noexcept = default;

      virtual ~EqualityExpressionImpl() = default;

  public: // Operators
      EqualityExpressionImpl& operator=(const EqualityExpressionImpl& cp) = default;
      EqualityExpressionImpl& operator=(EqualityExpressionImpl&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline double EqualityExpressionImpl<L, R>::eval() const {
      return Utils::deq(this->left(), this->right());
  }

  template<class L, class R>
  inline std::string EqualityExpressionImpl<L, R>::getPrintName() const {
      return "Eq";
  }

  template<class L, class R>
  inline EqualityExpressionImpl<L, R>::EqualityExpressionImpl(const L& lhs, const R& rhs)
          : CExpressionImpl<L, R>(lhs, rhs, std::nullopt) {}
}

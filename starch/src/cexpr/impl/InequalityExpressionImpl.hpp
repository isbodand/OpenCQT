//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "CExpressionImpl.hpp"
#include "../InequalityExpression.hpp"

namespace LibStarch {
  template<class L, class R>
  class InequalityExpressionImpl : public InequalityExpression,
                                   public CExpressionImpl<L, R> {
      using ImplOf = InequalityExpression;
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      InequalityExpressionImpl() = delete;
      InequalityExpressionImpl(const L& lhs, const R& rhs);
      InequalityExpressionImpl(const InequalityExpressionImpl& cp) = default;
      InequalityExpressionImpl(InequalityExpressionImpl&& mv) noexcept = default;

      virtual ~InequalityExpressionImpl() = default;

  public: // Operators
      InequalityExpressionImpl& operator=(const InequalityExpressionImpl& cp) = default;
      InequalityExpressionImpl& operator=(InequalityExpressionImpl&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline double InequalityExpressionImpl<L, R>::eval() const {
      return Utils::dne(this->left(), this->right());
  }

  template<class L, class R>
  inline std::string InequalityExpressionImpl<L, R>::getPrintName() const {
      return "Ne";
  }

  template<class L, class R>
  InequalityExpressionImpl<L, R>::InequalityExpressionImpl(const L& lhs, const R& rhs)
          : CExpressionImpl<L, R>(lhs, rhs) {}
}


//
// Created by bodand on 2019-06-29.
//

#pragma once

#include <iostream>

#include "CExpressionImpl.hpp"
#include "../AdditionExpression.hpp"

namespace LibStarch {
  template<class L, class R>
  class AdditionExpressionImpl : public AdditionExpression,
                                 public CExpressionImpl<L, R> {
      using ImplOf = AdditionExpression;
  public: // Methods
      virtual double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      AdditionExpressionImpl() = delete;
      AdditionExpressionImpl(L lhs, R rhs);
      AdditionExpressionImpl(const AdditionExpressionImpl& cp) = default;
      AdditionExpressionImpl(AdditionExpressionImpl&& mv) noexcept = default;

      virtual ~AdditionExpressionImpl() = default;

  public: // Operators
      AdditionExpressionImpl& operator=(const AdditionExpressionImpl& cp) = default;
      AdditionExpressionImpl& operator=(AdditionExpressionImpl&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline AdditionExpressionImpl<L, R>::AdditionExpressionImpl(L lhs, R rhs)
          : CExpressionImpl<L, R>(std::move(lhs), std::move(rhs), std::nullopt) {}

  template<class L, class R>
  inline double AdditionExpressionImpl<L, R>::eval() const {
      return this->left() + this->right();
  }

  template<class L, class R>
  inline std::string AdditionExpressionImpl<L, R>::getPrintName() const {
      return "Plus";
  }
}

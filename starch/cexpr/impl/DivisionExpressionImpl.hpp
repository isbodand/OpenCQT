//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "CExpressionImpl.hpp"
#include "../DivisionExpression.hpp"

namespace LibStarch {
  template<class L, class R>
  class DivisionExpressionImpl : public DivisionExpression,
                                 public CExpressionImpl<L, R> {
      using ImplOf = DivisionExpression;
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      DivisionExpressionImpl() = delete;
      DivisionExpressionImpl(const L& lhs, const R& rhs);
      DivisionExpressionImpl(const DivisionExpressionImpl& cp) = default;
      DivisionExpressionImpl(DivisionExpressionImpl&& mv) noexcept = default;

      virtual ~DivisionExpressionImpl() = default;

  public: // Operators
      DivisionExpressionImpl& operator=(const DivisionExpressionImpl& cp) = default;
      DivisionExpressionImpl& operator=(DivisionExpressionImpl&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline double DivisionExpressionImpl<L, R>::eval() const {
      return this->left() / this->right();
  }

  template<class L, class R>
  inline std::string DivisionExpressionImpl<L, R>::getPrintName() const {
      return "Div";
  }

  template<class L, class R>
  inline DivisionExpressionImpl<L, R>::DivisionExpressionImpl(const L& lhs, const R& rhs)
          :CExpressionImpl<L, R>(lhs, rhs, std::nullopt) {}
}

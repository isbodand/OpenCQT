//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "CExpressionImpl.hpp"
#include "../ModuloExpression.hpp"
#include <cmath>

namespace LibStarch {
  template<class L, class R>
  class ModuloExpressionImpl : public ModuloExpression,
                               public CExpressionImpl<L, R> {
      using ImplOf = ModuloExpression;
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      ModuloExpressionImpl() = delete;
      ModuloExpressionImpl(const L& lhs, const R& rhs);
      ModuloExpressionImpl(const ModuloExpressionImpl& cp) = default;
      ModuloExpressionImpl(ModuloExpressionImpl&& mv) noexcept = default;

      virtual ~ModuloExpressionImpl() = default;

  public: // Operators
      ModuloExpressionImpl& operator=(const ModuloExpressionImpl& cp) = default;
      ModuloExpressionImpl& operator=(ModuloExpressionImpl&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline double ModuloExpressionImpl<L, R>::eval() const {
      return std::fmod(this->left(), this->right());
  }

  template<class L, class R>
  inline std::string ModuloExpressionImpl<L, R>::getPrintName() const {
      return "Mod";
  }

  template<class L, class R>
  inline ModuloExpressionImpl<L, R>::ModuloExpressionImpl(const L& lhs, const R& rhs)
          : CExpressionImpl<L, R>(lhs, rhs, std::nullopt) {}
}

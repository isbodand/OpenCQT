//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "impl/CExpressionImpl.hpp"
#include <cmath>

namespace LibStarch {
  template<class L, class R>
  class ModuloExpression : public CExpressionImpl<L, R> {
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      ModuloExpression() = delete;
      ModuloExpression(const L& lhs, const R& rhs);
      ModuloExpression(const ModuloExpression& cp) = default;
      ModuloExpression(ModuloExpression&& mv) noexcept = default;

      virtual ~ModuloExpression() = default;

  public: // Operators
      ModuloExpression& operator=(const ModuloExpression& cp) = default;
      ModuloExpression& operator=(ModuloExpression&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline double ModuloExpression<L, R>::eval() const {
      return std::fmod(this->left(), this->right());
  }

  template<class L, class R>
  inline std::string ModuloExpression<L, R>::getPrintName() const {
      return "Mod";
  }

  template<class L, class R>
  inline ModuloExpression<L, R>::ModuloExpression(const L& lhs, const R& rhs)
          : CExpressionImpl<L, R>(lhs, rhs, std::nullopt) {}
}

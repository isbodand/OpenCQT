//
// Created by bodand on 2019-06-30.
//

#pragma once

#include "impl/CExpressionImpl.hpp"

namespace LibStarch {
  template<class L, class R>
  class LessThanExpression : public CExpressionImpl<L, R> {
  public: // Methods
      double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      LessThanExpression() = delete;
      LessThanExpression(const L& lhs, const R& rhs);
      LessThanExpression(const LessThanExpression& cp) = default;
      LessThanExpression(LessThanExpression&& mv) noexcept = default;

      virtual ~LessThanExpression() = default;

  public: // Operators
      LessThanExpression& operator=(const LessThanExpression& cp) = default;
      LessThanExpression& operator=(LessThanExpression&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline LessThanExpression<L, R>::LessThanExpression(const L& lhs, const R& rhs)
          : CExpressionImpl<L, R>(lhs, rhs) {}

  template<class L, class R>
  inline double LessThanExpression<L, R>::eval() const {
      return Utils::dlt(this->left(), this->right());
  }

  template<class L, class R>
  inline std::string LessThanExpression<L, R>::getPrintName() const {
      return "Lt";
  }
}

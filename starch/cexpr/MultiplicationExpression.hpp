//
// Created by bodand on 2019-06-30.
//

#pragma once

#include <ostream>
#include "impl/CExpressionImpl.hpp"

namespace LibStarch {
  template<class L, class R>
  class MultiplicationExpression : public CExpressionImpl<L, R> {
  public: // Methods
      double eval() const override;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      MultiplicationExpression() = delete;
      MultiplicationExpression(const L& lhs, const R& rhs);
      MultiplicationExpression(const MultiplicationExpression& cp) = default;
      MultiplicationExpression(MultiplicationExpression&& mv) noexcept = default;

      virtual ~MultiplicationExpression() = default;

  public: // Operators
      MultiplicationExpression& operator=(const MultiplicationExpression& cp) = default;
      MultiplicationExpression& operator=(MultiplicationExpression&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline double MultiplicationExpression<L, R>::eval() const {
      return this->left() * this->right();
  }

  template<class L, class R>
  inline MultiplicationExpression<L, R>::MultiplicationExpression(const L& lhs, const R& rhs)
          : CExpressionImpl<L, R>(lhs, rhs, std::nullopt) {}

  template<class L, class R>
  inline std::string MultiplicationExpression<L, R>::getPrintName() const {
      return "Times";
  }

}

//
// Created by bodand on 2019-06-30.
//

#pragma once

#include <ostream>
#include "CExpressionImpl.hpp"
#include "../MultiplicationExpression.hpp"

namespace LibStarch {
  template<class L, class R>
  class MultiplicationExpressionImpl : public MultiplicationExpression,
                                       public CExpressionImpl<L, R> {
      using ImplOf = MultiplicationExpression;
  public: // Methods
      double eval() const override;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      MultiplicationExpressionImpl() = delete;
      MultiplicationExpressionImpl(const L& lhs, const R& rhs);
      MultiplicationExpressionImpl(const MultiplicationExpressionImpl& cp) = default;
      MultiplicationExpressionImpl(MultiplicationExpressionImpl&& mv) noexcept = default;

      virtual ~MultiplicationExpressionImpl() = default;

  public: // Operators
      MultiplicationExpressionImpl& operator=(const MultiplicationExpressionImpl& cp) = default;
      MultiplicationExpressionImpl& operator=(MultiplicationExpressionImpl&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline double MultiplicationExpressionImpl<L, R>::eval() const {
      return this->left() * this->right();
  }

  template<class L, class R>
  inline MultiplicationExpressionImpl<L, R>::MultiplicationExpressionImpl(const L& lhs, const R& rhs)
          : CExpressionImpl<L, R>(lhs, rhs, std::nullopt) {}

  template<class L, class R>
  inline std::string MultiplicationExpressionImpl<L, R>::getPrintName() const {
      return "Times";
  }

}

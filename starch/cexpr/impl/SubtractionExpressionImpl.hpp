//
// Created by bodand on 2019-06-29.
//

#pragma once

#include <ostream>
#include "CExpressionImpl.hpp"
#include "../SubtractionExpression.hpp"

namespace LibStarch {
  template<class L, class R>
  class SubtractionExpressionImpl : public SubtractionExpression,
                                    public CExpressionImpl<L, R> {
      using ImplOf = SubtractionExpression;
  public: // Methods
      virtual double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      SubtractionExpressionImpl() = delete;
      SubtractionExpressionImpl(const L& lhs, const R& rhs);
      SubtractionExpressionImpl(const SubtractionExpressionImpl& cp) = default;
      SubtractionExpressionImpl(SubtractionExpressionImpl&& mv) noexcept = default;

      virtual ~SubtractionExpressionImpl() = default;

  public: // Operators
      SubtractionExpressionImpl& operator=(const SubtractionExpressionImpl& cp) = default;
      SubtractionExpressionImpl& operator=(SubtractionExpressionImpl&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline SubtractionExpressionImpl<L, R>::SubtractionExpressionImpl(const L& lhs,
                                                                    const R& rhs)
          : CExpressionImpl<L, R>(lhs, rhs, std::nullopt) {}

  template<class L, class R>
  inline double LibStarch::SubtractionExpressionImpl<L, R>::eval() const {
      return this->left() - this->right();
  }

  template<class L, class R>
  inline std::string SubtractionExpressionImpl<L, R>::getPrintName() const {
      return "Minus";
  }
}

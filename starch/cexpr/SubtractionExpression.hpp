//
// Created by bodand on 2019-06-29.
//

#pragma once

#include <ostream>
#include "impl/CExpressionImpl.hpp"

namespace LibStarch {
  template<class L, class R>
  class SubtractionExpression : public CExpressionImpl<L, R> {
  public: // Methods
      virtual double eval() const final;
      std::string getPrintName() const override;

  public: // Constructors & Destructor
      SubtractionExpression() = delete;
      SubtractionExpression(const L& lhs, const R& rhs);
      SubtractionExpression(const SubtractionExpression& cp) = default;
      SubtractionExpression(SubtractionExpression&& mv) noexcept = default;

      virtual ~SubtractionExpression() = default;

  public: // Operators
      SubtractionExpression& operator=(const SubtractionExpression& cp) = default;
      SubtractionExpression& operator=(SubtractionExpression&& mv) noexcept = default;

  private: // Fields
  private: // Methods
  };

  template<class L, class R>
  inline SubtractionExpression<L, R>::SubtractionExpression(const L& lhs,
                                                            const R& rhs)
          : CExpressionImpl<L, R>(lhs, rhs, std::nullopt) {}

  template<class L, class R>
  inline double LibStarch::SubtractionExpression<L, R>::eval() const {
      return this->left() - this->right();
  }

  template<class L, class R>
  inline std::string SubtractionExpression<L, R>::getPrintName() const {
      return "Minus";
  }
}

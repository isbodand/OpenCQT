//
// Created by bodand on 2019-07-08.
//

#pragma once

#include "CExpression.hpp"
#include "../utils/Makeable.hpp"

namespace LibStarch {
  template<class, class>
  class MultiplicationExpressionImpl;

  trait MultiplicationExpression : public virtual CExpression,
                                   public Makeable<MultiplicationExpressionImpl>,
                                   public Visiting::Visitable {
  public:
      void accept(Visiting::Visitor& visitor) override;
      Utils::ExprType getType() const override;
  };
}

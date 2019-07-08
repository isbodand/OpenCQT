//
// Created by bodand on 2019-07-08.
//

#pragma once

#include "CExpression.hpp"
#include "Makeable.hpp"

namespace LibStarch {
  template<class, class>
  class NegateExpressionImpl;

  trait NegateExpression : public virtual CExpression,
                           public Makeable<NegateExpressionImpl>,
                           public Visiting::Visitable {
  public:
      void accept(Visiting::Visitor& visitor) override;
  };
}


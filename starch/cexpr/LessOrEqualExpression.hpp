//
// Created by bodand on 2019-07-08.
//

#pragma once


#include "../Utils.hpp"
#include "CExpression.hpp"
#include "Makeable.hpp"

namespace LibStarch {
  template<class, class>
  class LessOrEqualExpressionImpl;

  trait LessOrEqualExpression : public virtual CExpression,
                                public Makeable<LessOrEqualExpressionImpl>,
                                public Visiting::Visitable {
  public:
      void accept(Visiting::Visitor& visitor) override;
  };
}

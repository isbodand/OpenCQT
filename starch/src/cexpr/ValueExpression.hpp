//
// Created by bodand on 2019-07-08.
//

#pragma once

#include "CExpression.hpp"
#include "../utils/Makeable.hpp"

namespace LibStarch {
  template<class>
  class ValueExpressionImpl;

  trait ValueExpression : public virtual CExpression,
                          public Makeable<ValueExpressionImpl>,
                          public Visiting::Visitable {
  public:
      void accept(Visiting::Visitor& visitor) override;
  };
}


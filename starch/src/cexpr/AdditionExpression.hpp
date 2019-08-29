//
// Created by bodand on 2019-07-07.
//

#pragma once

#include "CExpression.hpp"
#include "../Utils.hpp"
#include "../utils/Makeable.hpp"

namespace LibStarch {
  template<class, class>
  class AdditionExpressionImpl;

  trait AdditionExpression : public virtual CExpression,
                             public Makeable<AdditionExpressionImpl>,
                             public Visiting::Visitable {
  public:
      void accept(Visiting::Visitor& visitor) override;
  };
}

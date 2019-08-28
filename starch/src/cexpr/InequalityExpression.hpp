//
// Created by bodand on 2019-07-08.
//

#pragma once


#include "../Utils.hpp"
#include "Makeable.hpp"
#include "CExpression.hpp"

namespace LibStarch {
  template<class, class>
  class InequalityExpressionImpl;

  trait InequalityExpression : public virtual CExpression,
                               public Makeable<InequalityExpressionImpl>,
                               public Visiting::Visitable {
  public:
      void accept(Visiting::Visitor& visitor) override;
  };
}

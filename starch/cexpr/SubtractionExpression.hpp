//
// Created by bodand on 2019-07-08.
//

#pragma once


#include "CExpression.hpp"
#include "Makeable.hpp"

namespace LibStarch {
  template<class, class>
  class SubtractionExpressionImpl;

  trait SubtractionExpression : public virtual CExpression,
                                public Makeable<SubtractionExpressionImpl>,
                                public Visiting::Visitable {
  public:
      void accept(Visiting::Visitor& visitor) override;
  };
}

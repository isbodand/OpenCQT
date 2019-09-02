//
// Created by bodand on 2019-07-08.
//

#pragma once


#include "../Utils.hpp"
#include "CExpression.hpp"
#include "../utils/Makeable.hpp"


namespace LibStarch {
  template<class, class>
  class EqualityExpressionImpl;

  trait EqualityExpression : public virtual CExpression,
                             public Makeable<EqualityExpressionImpl>,
                             public Visiting::Visitable {
  public:
      void accept(Visiting::Visitor& visitor) override;
      Utils::ExprType getType() const override;
  };
}

//
// Created by bodand on 2019-07-08.
//

#pragma once


#include "CExpression.hpp"
#include "../utils/Makeable.hpp"

namespace LibStarch {
  template<class, class>
  class ModuloExpressionImpl;

  trait ModuloExpression : public virtual CExpression,
                           public Makeable<ModuloExpressionImpl>,
                           public Visiting::Visitable {
  public:
      void accept(Visiting::Visitor& visitor) override;
  };
}

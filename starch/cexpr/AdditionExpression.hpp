//
// Created by bodand on 2019-07-07.
//

#pragma once

#include "CExpression.hpp"
#include "../Utils.hpp"

namespace LibStarch {
  using Utils::Ptr;
  using Utils::mkPtr;

  class AdditionExpression : public CExpression {
      /// Interface
  public:
      template<class L, class R>
      static Ptr<AdditionExpression> construct(L lhs, R rhs);

      /// Constructors
  public:
      AdditionExpression() = delete;

  protected:
      AdditionExpression(const AdditionExpression& cp) = default;
      AdditionExpression(AdditionExpression&& mv) noexcept = default;

      /// Destructor
  public:
      virtual ~AdditionExpression() = default;

      /// Operators
  public:
      AdditionExpression& operator=(const AdditionExpression& cp) = default;
      AdditionExpression& operator=(AdditionExpression&& mv) noexcept = default;

      /// Fields
  private:

      /// Methods
  private:
  };
}

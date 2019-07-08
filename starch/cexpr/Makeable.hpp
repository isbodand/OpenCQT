//
// Created by bodand on 2019-07-08.
//

#pragma once

#include <optional>

#include "../Utils.hpp"
#include "../CondNode.hpp"

namespace LibStarch {
  template<template<class, class> class T>
  trait Makeable {
      /// Interface
  public:
      template<class L, class R>
      static T<L, R>* make(const L& lhs, const R& rhs);
  };

  template<class, class>
  class TernaryExpressionImpl;

  template<>
  trait Makeable<TernaryExpressionImpl> {
      /// Interface
  public:
      template<class L, class R>
      static TernaryExpressionImpl<L, R>* make(const L& lhs, const R& rhs,
                                               const std::optional<CondNode>& cond);
  };

  template<class L, class R>
  TernaryExpressionImpl<L, R>*
  Makeable<TernaryExpressionImpl>::make(const L& lhs, const R& rhs,
                                        const std::optional<CondNode>& cond) {
      return new TernaryExpressionImpl<L, R>(lhs, rhs, cond);
  }

  template<template<class, class> class T>
  template<class L, class R>
  T<L, R>* Makeable<T>::make(const L& lhs, const R& rhs) {
      return new T(lhs, rhs);
  }
}

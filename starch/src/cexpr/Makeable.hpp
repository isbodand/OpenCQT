//
// Created by bodand on 2019-07-08.
//

#pragma once

#include <optional>

#include "../Utils.hpp"
#include "../CondNode.hpp"

namespace LibStarch {
  template<template<class...> class T>
  trait Makeable {
      /// Interface
  public:
      template<class... Args>
      static T<Args...>* make(Args&& ... params);

      template<class... Args>
      static Ptr <T<Args...>> makePtr(Args&& ... params);
  };

  template<class, class>
  class TernaryExpressionImpl;

  template<>
  trait Makeable<TernaryExpressionImpl> {
      /// Interface
  public:
      template<class L, class R>
      static TernaryExpressionImpl<L, R>* make(L&& lhs, R&& rhs,
                                               std::optional<CondNode>&& cond) {
          return new TernaryExpressionImpl<L, R>(std::forward<L>(lhs),
                                                 std::forward<R>(rhs),
                                                 std::forward<std::optional<CondNode>>(cond));
      }

      template<class L, class R>
      static Ptr <TernaryExpressionImpl<L, R>> makePtr(L&& lhs, R&& rhs,
                                                       std::optional<CondNode>&& cond) {
          return mkPtr<TernaryExpressionImpl<L, R>>(std::forward<L>(lhs),
                                                    std::forward<R>(rhs),
                                                    std::forward<std::optional<CondNode>>(cond));
      }
  };

  template<template<class...> class T>
  template<class... Args>
  inline T<Args...>* Makeable<T>::make(Args&& ... params) {
      return new T<Args...>(std::forward<Args>(params)...);
  }

  template<template<class...> class T>
  template<class... Args>
  inline Ptr <T<Args...>> Makeable<T>::makePtr(Args&& ... params) {
      return mkPtr<T<Args...>>(std::forward<Args>(params)...);
  }
}

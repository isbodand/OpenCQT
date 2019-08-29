//
// Created by bodand on 2019-08-29.
//

#pragma once

#include <type_traits>
#include <typeindex>
#include <utility>
#include <map>
#include <variant>

namespace LibStarch::Experimental {
  template<class T, class... Args>
  class Buildable {
      class Builder;
      /// Interface
  public:


      /// Fields
  private:

      /// Methods
  private:
      class Builder {
          T build();

          template<class _T>
          Builder& with(_T arg);

          std::map<std::type_index, void*> params;
      };
  };

  template<class T, class... Args>
  T Buildable<T, Args...>::Builder::build() {
      return T();
  }

  template<class T, class... Args>
  template<class _T>
  typename Buildable<T, Args...>::Builder& Buildable<T, Args...>::Builder::with(_T arg) {
      params[typeid(_T)] = (void*) &arg;
      return *this;
  }

}

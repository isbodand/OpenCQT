//
// Created by bodand on 2019-06-29.
//

#pragma once

#include <ostream>
#include <sstream>
#include "Utils.hpp"
//#include "val_subtrees/ValExpr.hpp"

namespace LibStarch {
  using Utils::Ptr;
  using Utils::mkPtr;

  class ValExpr;

  class CondNode {
      class Builder;

      /// Interface
  public:
      [[nodiscard]] bool eval() const;
      [[nodiscard]] const Ptr <ValNode>& getVal() const;

      static Builder getBuilder();

      /// Lifecycle
  public:
      CondNode() = delete;
      CondNode(ValNode* valNode);

      template<template<class, class> class E, class L, class R>
      CondNode(E<L, R>* expr)
           : val(std::make_shared<ValExpr>(expr)) {}

      /// Operators
  public:
      friend std::ostream& operator<<(std::ostream& os, const CondNode& node);

      /// Fields
  private:
      Ptr <ValNode> val = nullptr;

      /// Internals
  private:
      class Builder {

          [[nodiscard]] CondNode build() const;

          Builder& withValue(ValNode* val);
          template<template<class, class> class E, class L, class R>
          Builder& withExpression(E<L, R> expr);

          /// Fields
      private:
          ValNode* _val = nullptr;
      };
  };

}

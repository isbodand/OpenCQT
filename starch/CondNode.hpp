//
// Created by bodand on 2019-06-29.
//

#pragma once

#include <ostream>
#include <sstream>
#include "Utils.hpp"
#include "val_subtrees/ValExpr.hpp"

namespace LibStarch {
  using Utils::Ptr;
  using Utils::mkPtr;

  class CondNode {
  public: // Methods
      bool eval() const;

  public: // Constructors & Destructor
      CondNode() = default;
      CondNode(ValNode* valNode);

      template<template<class, class> class E, class L, class R>
      CondNode(E<L, R> expr) : val(std::make_shared<ValExpr>(std::move(expr))) {}

      CondNode(const CondNode& cp) = default;
      CondNode(CondNode&& mv) noexcept = default;

      ~CondNode() = default;

  public: // Operators
      CondNode& operator=(const CondNode& cp) = default;
      CondNode& operator=(CondNode&& mv) noexcept = default;

      friend std::ostream& operator<<(std::ostream& os, const CondNode& node);

  private: // Fields
      Ptr<ValNode> val = nullptr;

  private: // Methods
  };

}

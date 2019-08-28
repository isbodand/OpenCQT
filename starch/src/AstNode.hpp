//
// Created by tudom on 2019-05-29.
//

#pragma once

#include <vector>
#include <memory>

#include "Visitable.hpp"

namespace LibStarch {
  class ASTNode : public Visiting::Visitable {
  protected: // Protected constructors
      ASTNode() = default;
      ASTNode(const ASTNode& cp) = default;
      ASTNode(ASTNode&& mv) noexcept = default;

  public: // Destructor
      virtual ~ASTNode() = default;

  public: // Operators
      ASTNode& operator=(const ASTNode& cp) = default;
      ASTNode& operator=(ASTNode&& mv) noexcept = default;
  };
}


//
// Created by bodand on 2019-07-01.
//

#pragma once

#include <string>
#include <ostream>
#include <optional>

#include "../Utils.hpp"
#include "../CondNode.hpp"

namespace LibStarch {
  using Utils::Ptr;
  using Utils::mkPtr;
  using Utils::Anything;

  class CExpression {
      /// Interface
  public:
      [[nodiscard]] virtual double eval() const = 0;
      [[nodiscard]] virtual Utils::ExprType getType() const = 0;
      [[nodiscard]] virtual std::string getPrintName() const = 0;
      virtual void leftAsString(std::ostream& os) const = 0;
      virtual void rightAsString(std::ostream& os) const = 0;
      virtual void condAsString(std::ostream& os) const = 0;

      [[nodiscard]] virtual const std::optional<LibStarch::CondNode>& getCond() const = 0;

      [[nodiscard]] virtual Anything getAnyLeft() const = 0;
      [[nodiscard]] virtual Anything getAnyRight() const = 0;

      /// Constructors & Destructor
  public:
      CExpression() = default;
      CExpression(const CExpression& cp) = default;
      CExpression(CExpression&& mv) noexcept = default;

      virtual ~CExpression() = default;

      /// Operators
  public:
      CExpression& operator=(const CExpression& cp) = default;
      CExpression& operator=(CExpression&& mv) noexcept = default;

      friend std::ostream& operator<<(std::ostream& os,
                                      const CExpression& expression) {
          os << "[" << expression.getPrintName()
             << "(" << expression.eval() << ")"
             << " lhs: ";
          expression.leftAsString(os);
          os << " rhs: ";
          expression.rightAsString(os);
          os << " cond: ";
          expression.condAsString(os);
          os << "]";
          return os;
      }

      /// Fields
  private:

      /// Methods
  private:
  };
}

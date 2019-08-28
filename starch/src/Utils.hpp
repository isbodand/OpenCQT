//
// Created by tudom on 2019-05-29.
//

#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <variant>
#include "val_subtrees/ValNode.hpp"

#define trait class
#define unless(x) if(!(x))

namespace LibStarch::Utils {
  namespace Impl {
    // Types
    enum Types_ {
        typeTrueScalar, typeCharScalar,
        typeFlatArray, typeCompArray,
        typeHashMap, typeTreeMap,
        typeReference,          // don't joke about these, you know full
        typeFunction            // well these will never get implemented
    };
    enum Instruction_ {
        instPlus, instMinus,
        instStepForward, instStepBackward,
        instStepInto, instStepOut,
        instPrint, instRead,
        instInvocation
    };
    enum Expr_ {
        exprAddition,
        exprSubtraction,
        exprMultiplication,
        exprDivision,
        exprModulo,
        exprValue,
        exprNegate,
        exprTernary,
        exprEquality,
        exprInequality,
        exprGreaterThan,
        exprGreaterOrEqual,
        exprLessThan,
        exprLessOrEqual
    };
    enum Val_ {
        valValExpr,
        valValText,
        valValNumber,
        valValID,
    };
    // Sub Parameters
    struct ASTSubParams_ {
        struct ValType {
            union ValType_ {
                long scalar;
                void* vectorial;
            };
            int used;
            ValType_ val;

            ValType();
            ValType(long scalar);
            ValType(std::initializer_list<std::string> vectorial);

            ValType& operator=(long scalar);
            ValType& operator=(std::vector<std::string> vectorial);

            ~ValType();
        };

        bool advanced;
        ValType val;

        ASTSubParams_(long num);
        ASTSubParams_(std::initializer_list<std::string> str);
    };

    // Type-ctor
    struct ASTTypeCtor_ {
        Types_ type;
        std::shared_ptr<ValNode> val;

        ASTTypeCtor_(Types_ type, ValNode* val);
    };

    // Void expression
    template<class L, class R>
    struct VoidExpr_ {
        [[nodiscard]] bool eval() const;
        operator bool();
        operator int();

        friend std::ostream& operator<<(std::ostream& os, const VoidExpr_& expr) {
            os << "[VoidExpr]";
            return os;
        }
    };
  }

  template<class L=void, class R=void>
  using VoidExpr = Impl::VoidExpr_<L, R>;

  template<class T>
  using Inst = std::unique_ptr<T>;

  template<class T>
  using Ptr = std::shared_ptr<T>;

  template<class T, class... Args>
  constexpr Inst<T> mkInst(Args... args) {
      return std::make_unique<T>(args...);
  }

  template<class T, class... Args>
  constexpr Ptr<T> mkPtr(Args... args) {
      return std::make_shared<T>(args...);
  }

  using ASTSubParams = Impl::ASTSubParams_;
  using TypeCtor = Impl::ASTTypeCtor_;
  using Type = Impl::Types_;
  using Instruction = Impl::Instruction_;
  using ValType = Impl::Val_;
  using ExprType = Impl::Expr_;

  bool deq(double a, double b);
  bool dne(double a, double b);
  bool dgt(double a, double b);
  bool dlt(double a, double b);
  bool dge(double a, double b);
  bool dle(double a, double b);
}

namespace std {
  std::string to_string(LibStarch::Utils::Type type);
  std::string to_string(LibStarch::Utils::Instruction type);
  std::string to_string(LibStarch::AdditionExpression& expr);
  std::string to_string(LibStarch::SubtractionExpression& expr);
  std::string to_string(LibStarch::MultiplicationExpression& expr);
  std::string to_string(LibStarch::DivisionExpression& expr);
  std::string to_string(LibStarch::ModuloExpression& expr);
  std::string to_string(LibStarch::ValueExpression& expr);
  std::string to_string(LibStarch::NegateExpression& expr);
  std::string to_string(LibStarch::TernaryExpression& expr);
  std::string to_string(LibStarch::EqualityExpression& expr);
  std::string to_string(LibStarch::InequalityExpression& expr);
  std::string to_string(LibStarch::GreaterThanExpression& expr);
  std::string to_string(LibStarch::GreaterOrEqualExpression& expr);
  std::string to_string(LibStarch::LessThanExpression& expr);
  std::string to_string(LibStarch::LessOrEqualExpression& expr);
  std::string to_string(LibStarch::ValExpr& val);
  std::string to_string(LibStarch::ValText& val);
  std::string to_string(LibStarch::ValNumber& val);
  std::string to_string(LibStarch::ValID& val);
}

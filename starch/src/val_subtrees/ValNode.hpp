//
// Created by bodand on 2019-06-20.
//

#pragma once

#include <ostream>
#include <memory>

#include "../Visitable.hpp"

namespace LibStarch {
  template<class T>
  using _Ptr = std::shared_ptr<T>;

  class ValNode : public Visiting::Visitable {
      /// Interface
  public:
      [[nodiscard]] virtual double eval() const = 0;
      virtual void asString(std::ostream& os) const = 0;
      [[nodiscard]] virtual std::string getVal() const = 0;

      // Maker methods
      static ValNode* mkID(std::string idName);
      static ValNode* mkID(const char* idName);
      template<class Expr>
      static ValNode* mkExpr(Expr* expr_);
      static ValNode* mkNumber(double value);
      static ValNode* mkText(std::string idName);
      static ValNode* mkText(const char* idName);
      // Smart pointer impl
      static _Ptr<ValNode> mkPtrID(std::string&& idName);
      static _Ptr<ValNode> mkPtrID(const char* idName);
      template<class Expr>
      static _Ptr<ValNode> mkPtrExpr(Expr* expr_);
      static _Ptr<ValNode> mkPtrNumber(double value);
      static _Ptr<ValNode> mkPtrText(std::string&& idName);
      static _Ptr<ValNode> mkPtrText(const char* idName);

      /// Lifecycle
  protected:
      ValNode() = default;
      ValNode(const ValNode& cp) = default;
      ValNode(ValNode&& mv) noexcept = default;

  public:
      virtual ~ValNode() = default;

      /// Operators
  public:
      ValNode& operator=(const ValNode& cp) = default;
      ValNode& operator=(ValNode&& mv) noexcept = default;

      friend std::ostream& operator<<(std::ostream& os, const ValNode& node);
  };
}

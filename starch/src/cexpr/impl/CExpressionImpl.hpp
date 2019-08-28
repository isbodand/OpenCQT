//
// Created by bodand on 2019-06-29.
//

#pragma once

#include <optional>
#include <ostream>
#include <sstream>
#include <utility>

#include "../../val_subtrees/ValNode.hpp"
#include "../../Utils.hpp"
#include "../CExpression.hpp"

namespace LibStarch {
  using Utils::Ptr;
  using Utils::mkPtr;
  using Utils::mkPtr;

  template<class L, class R>
  class CExpressionImpl : public virtual CExpression {
  public: // Methods
      [[nodiscard]] const L* getLeft() const;
      [[nodiscard]] const R* getRight() const;
      [[nodiscard]] double left() const;
      [[nodiscard]] double right() const;
      [[nodiscard]] const std::optional<CondNode>& getCond() const override;

      void leftAsString(std::ostream& os) const override;
      void rightAsString(std::ostream& os) const override;
      void condAsString(std::ostream& os) const override;

      [[nodiscard]] Anything getAnyLeft() const override;
      [[nodiscard]] Anything getAnyRight() const override;

  public: // Constructors & Destructor
      CExpressionImpl() = delete;
      CExpressionImpl(L lhs, R rhs,
                      std::optional<CondNode> cond);
      CExpressionImpl(L lhs, R rhs);
      CExpressionImpl(L lhs);
      CExpressionImpl(const CExpressionImpl& cp) = default;
      CExpressionImpl(CExpressionImpl&& mv) noexcept = default;

      ~CExpressionImpl() override = default;

  public: // Operators
      CExpressionImpl& operator=(const CExpressionImpl& cp) = default;
      CExpressionImpl& operator=(CExpressionImpl&& mv) noexcept = default;

  protected: // Fields
      Ptr<L> lhs;
      Ptr<R> rhs;
      std::optional<CondNode> cond;

  private: // Methods
  };


  template<class L, class R>
  inline CExpressionImpl<L, R>::CExpressionImpl(L lhs, R rhs,
                                                std::optional<CondNode> cond)
          : lhs(mkPtr<L>(std::move(lhs))),
            rhs(mkPtr<R>(std::move(rhs))),
            cond(std::move(cond)),
            CExpression() {
  }

  template<class L, class R>
  inline const L* CExpressionImpl<L, R>::getLeft() const {
      return lhs.get();
  }

  template<class L, class R>
  inline const R* CExpressionImpl<L, R>::getRight() const {
      return rhs.get();
  }

  template<class L, class R>
  inline CExpressionImpl<L, R>::CExpressionImpl(L lhs, R rhs)
       : CExpressionImpl<L, R>(std::move(lhs), std::move(rhs), std::nullopt) {}

  template<class L, class R>
  inline double CExpressionImpl<L, R>::left() const {
      return lhs->eval();
  }

  template<class L, class R>
  inline double CExpressionImpl<L, R>::right() const {
      return rhs->eval();
  }

  template<class L, class R>
  inline CExpressionImpl<L, R>::CExpressionImpl(L lhs)
          : lhs(std::make_unique<L>(std::move(lhs))),
            rhs(),
            cond(),
            CExpression() {
  }

  template<class L, class R>
  inline void CExpressionImpl<L, R>::leftAsString(std::ostream& os) const {
      if (this->getLeft())
          os << *this->getLeft();
      else
          os << "[empty]";
  }

  template<class L, class R>
  inline void CExpressionImpl<L, R>::rightAsString(std::ostream& os) const {
      if (this->getRight())
          os << *this->getRight();
      else
          os << "[empty]";
  }

  template<class L, class R>
  inline void CExpressionImpl<L, R>::condAsString(std::ostream& os) const {
      if (this->getCond().has_value())
          os << *this->getCond();
      else
          os << "[empty]";
  }

  template<class L, class R>
  inline Anything CExpressionImpl<L, R>::getAnyLeft() const {
      return {getLeft(), []() -> Utils::ValType {
        if constexpr (std::is_same_v<L, ValText>) {
            return Utils::Impl::valValText;
        } else if constexpr (std::is_same_v<L, ValExpr>) {
            return Utils::Impl::valValExpr;
        } else if constexpr (std::is_same_v<L, ValNumber>) {
            return Utils::Impl::valValNumber;
        } else if constexpr (std::is_same_v<L, ValID>) {
            return Utils::Impl::valValID;
        }
      }()};
  }

  template<class L, class R>
  inline Anything CExpressionImpl<L, R>::getAnyRight() const {
      return {getRight(), []() -> Utils::ValType {
        if constexpr (std::is_same_v<R, ValText>) {
            return Utils::Impl::valValText;
        } else if constexpr (std::is_same_v<R, ValExpr>) {
            return Utils::Impl::valValExpr;
        } else if constexpr (std::is_same_v<R, ValNumber>) {
            return Utils::Impl::valValNumber;
        } else if constexpr (std::is_same_v<R, ValID>) {
            return Utils::Impl::valValID;
        }
      }()};
  }

  template<class L, class R>
  const std::optional<CondNode>& CExpressionImpl<L, R>::getCond() const {
      return cond;
  }
}

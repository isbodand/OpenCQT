//
// Created by bodand on 2019-06-20.
//

#include "ValNode.hpp"

#include <utility>

std::ostream& LibStarch::operator<<(std::ostream& os, const LibStarch::ValNode& node) {
    node.asString(os);
    return os;
}

#include "ValId.hpp"

LibStarch::ValNode* LibStarch::ValNode::mkID(std::string idName) {
    return new ValID(std::move(idName));
}

LibStarch::ValNode* LibStarch::ValNode::mkID(const char* idName) {
    return new ValID(idName);
}

LibStarch::_Ptr<LibStarch::ValNode>
LibStarch::ValNode::mkPtrID(std::string&& idName) {
    return std::make_shared<ValID>(std::forward<std::string>(idName));
}

LibStarch::_Ptr<LibStarch::ValNode>
LibStarch::ValNode::mkPtrID(const char* idName) {
    return std::make_shared<ValID>(idName);
}

#include "ValExpr.hpp"

template<class Expr>
LibStarch::ValNode* LibStarch::ValNode::mkExpr(Expr* expr_) {
    return new ValExpr(expr_);
}

template<class Expr>
LibStarch::_Ptr<LibStarch::ValNode>
LibStarch::ValNode::mkPtrExpr(Expr* expr_) {
    return std::make_shared<ValExpr>(expr_);
}

#include "ValNumber.hpp"

LibStarch::ValNode* LibStarch::ValNode::mkNumber(double num) {
    return new ValNumber(num);
}

LibStarch::_Ptr<LibStarch::ValNode>
LibStarch::ValNode::mkPtrNumber(double num) {
    return std::make_shared<ValNumber>(num);
}

#include "ValText.hpp"

LibStarch::ValNode* LibStarch::ValNode::mkText(std::string idName) {
    return new ValText(std::move(idName));
}

LibStarch::ValNode* LibStarch::ValNode::mkText(const char* idName) {
    return new ValText(idName);
}

LibStarch::_Ptr<LibStarch::ValNode>
LibStarch::ValNode::mkPtrText(std::string&& idName) {
    return std::make_shared<ValText>(std::forward<std::string>(idName));
}

LibStarch::_Ptr<LibStarch::ValNode>
LibStarch::ValNode::mkPtrText(const char* idName) {
    return std::make_shared<ValText>(idName);
}

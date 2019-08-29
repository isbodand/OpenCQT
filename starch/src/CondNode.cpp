//
// Created by bodand on 2019-06-29.
//

#include "CondNode.hpp"

bool LibStarch::CondNode::eval() const {
    if (val) {
        return Utils::dne(val->eval(), 0.0);
    }
    return false;
}

LibStarch::CondNode::CondNode(ValNode* valNode)
        : val(valNode) {
}

std::ostream& LibStarch::operator<<(std::ostream& os, const LibStarch::CondNode& node) {
    os << "[Condition val: ";
    node.val->asString(os);
    os << "]";
    return os;
}

const LibStarch::Ptr<LibStarch::ValNode>& LibStarch::CondNode::getVal() const {
    return val;
}

LibStarch::CondNode::Builder LibStarch::CondNode::getBuilder() {
    return LibStarch::CondNode::Builder();
}

LibStarch::CondNode LibStarch::CondNode::Builder::build() const {
    return LibStarch::CondNode(_val);
}

LibStarch::CondNode::Builder& LibStarch::CondNode::Builder::withValue(LibStarch::ValNode* val) {
    _val = val;
    return *this;
}

template<template<class, class> class E, class L, class R>
LibStarch::CondNode::Builder& LibStarch::CondNode::Builder::withExpression(E<L, R> expr) {
    _val = ValNode::mkExpr(expr);
    return *this;
}

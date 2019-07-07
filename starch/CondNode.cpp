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

//LibStarch::CondNode::~CondNode() {
//    delete val;
//}

std::ostream& LibStarch::operator<<(std::ostream& os, const LibStarch::CondNode& node) {
    os << "[Condition val: ";
    node.val->asString(os);
    os << "]";
    return os;
}

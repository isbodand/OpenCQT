//
// Created by bodand on 2019-06-20.
//

#include "ValNode.hpp"

std::ostream& LibStarch::operator<<(std::ostream& os, const LibStarch::ValNode& node) {
    node.asString(os);
    return os;
}

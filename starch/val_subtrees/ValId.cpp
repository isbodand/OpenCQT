#include <utility>

//
// Created by bodand on 2019-06-20.
//

#include "ValId.hpp"

LibStarch::ValID::ValID(std::string idName)
        : idName(std::move(idName)) {}

const std::string& LibStarch::ValID::getIdName() const {
    return idName;
}

LibStarch::ValID::ValID(const char* idName)
        : idName(std::string(idName)) {

}

double LibStarch::ValID::eval() const {
    return 0;
}

void LibStarch::ValID::asString(std::ostream& os) const {
    os << "[ValID \"" << idName << "\"]";
}

void LibStarch::ValID::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}


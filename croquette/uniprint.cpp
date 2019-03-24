//
// Created by bodand on 2019-03-24.
//

#include "uniprint.hpp"

void LibCroquette::uniPrint(const LibCroquette::_CqtString& string) {
    _CqtSTDOUT << string;
}

LibCroquette::_CqtString LibCroquette::uniReadStr() {
    _CqtString str;
    _CqtSTDIN >> str;
    return std::move(str);
}

void LibCroquette::uniError(const LibCroquette::_CqtString& error) {
    _CqtSTDERR << error;
}

//
// Created by bodand on 2019-03-24.
//

#include "uniprint.hpp"

void LibCroquette::uniPrint(const LibCroquette::String& string) {
    CQT_STDOUT << string;
}

LibCroquette::String LibCroquette::uniReadStr() {
    String str;
    CQT_STDIN >> str;
    return std::move(str);
}

void LibCroquette::uniError(const LibCroquette::String& error) {
    CQT_STDERR << error;
}

LibCroquette::Char LibCroquette::uniReadChar() {
    Char ch;
    CQT_STDIN >> ch;
    return ch;
}

//
// Created by bodand on 2019-03-24.
//

#include "uniprint.hpp"

void LibCqt::uniPrint(const LibCqt::String& string) {
    CQT_STDOUT << string;
}

LibCqt::String LibCqt::uniReadStr() {
    String str;
    CQT_STDIN >> str;
    return std::move(str);
}

void LibCqt::uniError(const LibCqt::String& error) {
    CQT_STDERR << error;
}

LibCqt::Char LibCqt::uniReadChar() {
    Char ch;
    CQT_STDIN >> ch;
    return ch;
}

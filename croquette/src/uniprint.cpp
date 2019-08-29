//
// Created by bodand on 2019-03-24.
//

#include "uniprint.hpp"

#include <locale>
#include <codecvt>
#include <string>

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

LibCqt::String LibCqt::operator ""_cqt(const char* str, std::size_t) {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
#ifdef _CQT_WINDOWS
    return converter.from_bytes(str);
#else
    return String(str);
#endif
}


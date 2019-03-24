//
// Created by bodand on 2019-03-24.
//

#pragma once

#include <iostream>
#include <string>

#if defined(_WIN64) || defined(_WIN32)

  #include <io.h>
  #include <fcntl.h>
  #include <winnt.h>

  #define _CQT_WINDOWS
#endif

namespace LibCroquette {

#ifdef _CQT_WINDOWS
    using _CqtChar = wchar_t;
    using _CqtString = std::wstring;

    auto& _CqtSTDOUT = std::wcout;

    auto& _CqtSTDERR = std::wcerr;

    auto& _CqtSTDIN = std::wcin;

  #define CQT_STRING(str) TEXT(str)
#else
    using _CqtChar = char;
    using _CqtString = std::string;

    auto& _CqtSTDOUT = std::cout;

    auto& _CqtSTDERR = std::cerr;

    auto& _CqtSTDIN = std::cin;

  #define CQT_STRING(str) str
#endif

    void uniPrint(const _CqtString& string);

    void uniError(const _CqtString& error);

    _CqtString uniReadStr();

    _CqtChar uniReadChar();
}
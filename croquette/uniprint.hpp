//
// Created by bodand on 2019-03-24.
//

#pragma once

#include <iostream>
#include <string>
#include <sstream>

#if (defined(_WIN64) || defined(_WIN32)) && !defined(_CQT_WINDOWS)

  #include <windows.h>
  #include <io.h>
  #include <fcntl.h>

  #define _CQT_WINDOWS
#endif

namespace LibCqt {

#if defined(_CQT_WINDOWS) && !defined(_CQT_STRING_INIT)
    using Char = wchar_t;
    using String = std::wstring;
    using StringStream = std::wstringstream;

  #ifndef CQT_STDOUT
    #define CQT_STDOUT std::wcout
  #endif

  #ifndef CQT_STDERR
    #define CQT_STDERR std::wcerr
  #endif

  #ifndef CQT_STDIN
    #define CQT_STDIN std::wcin
  #endif

  #ifndef CQT_STRING
    #define CQT_STRING(STR) std::wstring{L##STR}
  #endif

  #ifndef CQT_CHAR
    #define CQT_CHAR(CH) L##CH
  #endif

  #define _CQT_STRING_INIT
#elif !defined(_CQT_STRING_INIT)
    using Char = char;
    using String = std::string;
    using StringStream = std::stringstream;

  #ifndef CQT_STDOUT
    #define CQT_STDOUT std::cout
  #endif

  #ifndef CQT_STDERR
    #define CQT_STDERR std::cerr
  #endif

  #ifndef CQT_STDIN
    #define CQT_STDIN std::cin
  #endif

  #ifndef CQT_STRING
    #define CQT_STRING(STR) std::string{STR}
  #endif

  #ifndef CQT_CHAR
    #define CQT_CHAR(CH) CH
  #endif

  #define _CQT_STRING_INIT
#endif

    void uniPrint(const String& string);

    void uniError(const String& error);

    String uniReadStr();

    Char uniReadChar();
}
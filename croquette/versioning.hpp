#pragma once

#define LibCroquette_MAJOR 0
#define LibCroquette_MINOR 1
#if defined(_WIN64) || defined(_WIN32)
#  define LibCroquette_VERSION L"0.1-β"
#else
#  define LibCroquette_VERSION "0.1-β"
#endif

#include <string>
//@formatter:off
namespace LibCqt {
#if defined(_WIN64) || defined(_WIN32)

  static const std::wstring getVersion() {
#else
      static const std::string getVersion() {
#endif
      return LibCroquette_VERSION;
  }
}

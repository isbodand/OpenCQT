//
// Created by bodand on 2019-03-24.
//

#include "cqt.hpp"
#include "uniprint.hpp"

int LibCroquette::init() {
#ifdef _CQT_WINDOWS
    _setmode(_fileno(stdout), _O_U16TEXT);
#endif
    return 0;
}

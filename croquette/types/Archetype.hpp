#pragma once

#include <type_traits>
#include "../uniprint.hpp"

namespace LibCroquette {
class _ArcheType {
protected:
    void* value;

    _ArcheType();
public:
    virtual _CQT_STR_TYPE asString() = 0;
};

using ArcheType = _ArcheType;
};
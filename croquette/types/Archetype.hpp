#pragma once

#include <type_traits>

namespace LibCroquette {
class _ArcheType {
protected:
    void* value;

    _ArcheType();
public:
};

using ArcheType = _ArcheType;
};
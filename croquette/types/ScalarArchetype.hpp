#pragma once

#include <iostream>
#include <string>

#include "Archetype.hpp"

namespace LibCroquette {

namespace _Inner {
    union _InnerTrueScalar {
        int IntegerScalar;
        float FloatScalar;
        double DoubleScalar;
        long double LongDoubleScalar;
    };
    using _ScalarInnerValue = _InnerTrueScalar;

    enum _InnerCurrentTrueScalarValue {
        IntegerSubtype,
        FloatSubtype,
        DoubleSubtype,
        LongDoubleSubtype
    };
    using _ScalarSubtype = _InnerCurrentTrueScalarValue;

    struct _InnerTrueScalarSubType {
        _ScalarInnerValue value;
        _ScalarSubtype subtype;
    };
    using _TrueScalarSubtype = _InnerTrueScalarSubType;
}

class _ScalarArchetype : public ArcheType {
public:
};

using ScalarArchetype = _ScalarArchetype;

} // LibCroquette

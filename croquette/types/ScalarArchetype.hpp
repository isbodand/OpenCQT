#pragma once

#define _Out_

#include "Archetype.hpp"

namespace LibCroquette {

namespace _Inner {
    union _InnerScalar {
        int IntegerScalar;
        float FloatScalar;
        double DoubleScalar;
        long double LongDoubleScalar;
    };
    
    enum _InnerCurrentScalarValue {
        IntegerSubtype,
        FloatSubtype,
        DoubleSubtype,
        LongDoubleSubtype
    };

    class _InnerScalarArcheValue {
        _ScalarInnerValue value;
        _ScalarSubtype subtype;

    public:
        int getCurrentValue(_Out_ void* pop)
    };

    using _ScalarInnerValue = _InnerScalar;
    using _ScalarSubtype = _InnerCurrentScalarValue;
    using _ScalarValue = _InnerScalarArcheValue;
}

class _ScalarArchetype : public ArcheType {

}

using ScalarArchetype = _ScalarArchetype;

} // LibCroquette

#pragma once

#include "Archetype.hpp"

namespace LibCroquette {

namespace _Inner {
    union _InnerScalar {
        int IntegerScalar;
        float FloatScalar;
        double DoubleScalar;
        long double LongDoubleScalar;
    };
    
    using _ScalarValue = _InnerScalar;
}

class _ScalarArchetype : public ArcheType {
    
}

using ScalarArchetype = _ScalarArchetype;

} // LibCroquette

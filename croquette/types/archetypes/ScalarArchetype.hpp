//
// Created by bodand on 2019-03-25.
//

#pragma once

#include "AnyArchetype.hpp"
#include "../ImplementationTypes.hpp"

namespace LibCqt {
    class ScalarArchetype : public AnyArchetype {
    protected:
        double value;
    public:
        ScalarArchetype();
        explicit ScalarArchetype(double value);
        ScalarArchetype(CRf<ScalarArchetype> copy);
        explicit ScalarArchetype(CRf<Ptr<ScalarArchetype>> ref);

        double getValue() const;
        void setValue(double _value);
    };
    /// Pointer types
    using ScalarArchetype_P = Ptr<ScalarArchetype>;
    using ScalarArchetype_R = Raw<ScalarArchetype>;
}



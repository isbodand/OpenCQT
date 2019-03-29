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
        ScalarArchetype(const ScalarArchetype& copy);
        explicit ScalarArchetype(const Ptr <ScalarArchetype>& ref);

        double getValue() const;
    };
}



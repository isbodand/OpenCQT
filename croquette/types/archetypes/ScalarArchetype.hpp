//
// Created by bodand on 2019-03-25.
//

#pragma once

#include "AnyArchetype.hpp"

namespace LibCqt {
    class ScalarArchetype : public AnyArchetype {
    protected:
        double value;
    public:
        ScalarArchetype();
        explicit ScalarArchetype(double value);
    };
}



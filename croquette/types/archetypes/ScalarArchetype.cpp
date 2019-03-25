//
// Created by bodand on 2019-03-25.
//

#include "ScalarArchetype.hpp"

LibCqt::ScalarArchetype::ScalarArchetype() : AnyArchetype(LibCqt::Scalar), value(0) {}

LibCqt::ScalarArchetype::ScalarArchetype(double value) : value(value) {}

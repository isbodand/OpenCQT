//
// Created by bodand on 2019-03-25.
//

#include "ScalarArchetype.hpp"

LibCqt::ScalarArchetype::ScalarArchetype() : AnyArchetype(LibCqt::Scalar), value(0) {}

LibCqt::ScalarArchetype::ScalarArchetype(double value) : value(value) {}

double LibCqt::ScalarArchetype::getValue() const {
    return value;
}

LibCqt::ScalarArchetype::ScalarArchetype(const LibCqt::ScalarArchetype& copy)
        : ScalarArchetype(copy.getValue()) {
}

LibCqt::ScalarArchetype::ScalarArchetype(const LibCqt::Ptr<LibCqt::ScalarArchetype>& ref)
        : ScalarArchetype(ref->getValue()) {
}

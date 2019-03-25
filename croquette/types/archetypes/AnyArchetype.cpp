//
// Created by bodand on 2019-03-25.
//

#include "AnyArchetype.hpp"

LibCqt::ArchetypeType LibCqt::AnyArchetype::getCurrentType() const {
    return currentType;
}

LibCqt::AnyArchetype::AnyArchetype(LibCqt::ArchetypeType currentType) : currentType(currentType) {}

LibCqt::String LibCqt::AnyArchetype::asString() {
    return std::move(CQT_STRING("(>_<´) The printing of a decayed type is undefined behaviour you utter failure."
                                "Imagine the shit you'd be in if I weren't here to cover your lazy to typecheck ass."
                                "This could result in immediate termination with less powerful and caring compilers."));
}

LibCqt::AnyArchetype::AnyArchetype() : currentType(LibCqt::Scalar) {}

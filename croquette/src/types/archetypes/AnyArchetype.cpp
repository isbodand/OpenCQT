//
// Created by bodand on 2019-03-25.
//

#include <codecvt>
#include <locale>
#include "AnyArchetype.hpp"

LibCqt::ArchetypeType LibCqt::AnyArchetype::getCurrentType() const {
    return currentType;
}

LibCqt::AnyArchetype::AnyArchetype(LibCqt::ArchetypeType currentType)
        : currentType(currentType) {}

LibCqt::String LibCqt::AnyArchetype::asString() const {
    return CQT_STRING("(>_<´) The printing of a decayed getScalarType is undefined behaviour you utter failure. "
                      "Imagine the shit you'd be in if I weren't here to cover your lazy to typecheck ass. "
                      "This could result in immediate termination with less powerful and caring compilers.");
}

LibCqt::AnyArchetype::AnyArchetype()
        : currentType(LibCqt::archScalar) {}

bool LibCqt::AnyArchetype::operator==(const LibCqt::AnyArchetype& rhs) const {
    return currentType == rhs.currentType;
}

bool LibCqt::AnyArchetype::operator!=(const LibCqt::AnyArchetype& rhs) const {
    return !(rhs == *this);
}

std::ostream& LibCqt::operator<<(std::ostream& os, const LibCqt::AnyArchetype& archetype) {
#ifdef _CQT_WINDOWS
    os << std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>>{}.to_bytes(archetype.asString());
#else
    os << archetype.asString();
#endif
    return os;
}

std::wostream& LibCqt::operator<<(std::wostream& os, const LibCqt::AnyArchetype& archetype) {
#ifndef _CQT_WINDOWS
    os << std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>>{}.from_bytes(archetype.asString());
#else
    os << archetype.asString();
#endif
    return os;
}

LibCqt::ScalarType LibCqt::AnyArchetype::getScalarType() const {
    return scalarAnyScalar;
}

LibCqt::ArrayType LibCqt::AnyArchetype::getArrayType() const {
    return arrayAnyArray;
}

LibCqt::HashType LibCqt::AnyArchetype::getHashType() const {
    return hashAnyHash;
}

LibCqt::ReferenceType LibCqt::AnyArchetype::getReferenceType() const {
    return refAnyReference;
}


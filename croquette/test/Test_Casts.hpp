//
// Created by bodand on 2019. 05. 23..
//

#pragma once

#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemberFunctionCanBeStaticInspection"
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <boost/test/included/unit_test.hpp>

#include "../types/user_types/TrueScalarType.hpp"
#include "../types/user_types/CharacterScalarType.hpp"
#include "../types/user_types/ComplexArrayType.hpp"
#include "../types/user_types/FlatArrayType.hpp"
#include "../types/user_types/casts/ArrayCast.hpp"
#include "../types/user_types/casts/ScalarCast.hpp"

#include "../types/archetypes/ArchetypeUtilities.hpp"

#include "../types/user_types/EqualityOperators.hpp"

using namespace LibCqt;

// Through Archetypes
BOOST_AUTO_TEST_CASE(Test_Casts_ArchetypeCastTrueScalarToFlatArray) {
    auto sc = mkPtr<TrueScalarType>(1);
    FlatArrayType arr{mkPtr<TrueScalarType>(1)};
    BOOST_CHECK_EQUAL(arr, *archetype_cast<FlatArrayType>(sc));
}

BOOST_AUTO_TEST_CASE(Test_Casts_ArchetypeCastTrueScalarToComplexArray) {
    auto sc = mkPtr<TrueScalarType>(1);
    ComplexArrayType arr{mkPtr<TrueScalarType>(1)};
    BOOST_CHECK_EQUAL(arr, *archetype_cast<ComplexArrayType>(sc));
}

BOOST_AUTO_TEST_CASE(Test_Casts_ArchetypeCastCharScalarToFlatArray) {
    auto sc = mkPtr<CharacterScalarType>(1);
    FlatArrayType arr{mkPtr<CharacterScalarType>(1)};
    BOOST_CHECK_EQUAL(arr, *archetype_cast<FlatArrayType>(sc));
}

BOOST_AUTO_TEST_CASE(Test_Casts_ArchetypeCastCharScalarToComplexArray) {
    auto sc = mkPtr<CharacterScalarType>(1);
    ComplexArrayType arr{mkPtr<CharacterScalarType>(1)};
    BOOST_CHECK_EQUAL(arr, *archetype_cast<ComplexArrayType>(sc));
}

BOOST_AUTO_TEST_CASE(Test_Casts_ArchetypeCastFlatArrayToTrueScalar) {
    auto sc = mkPtr<TrueScalarType>(1);
    auto arr = mkPtr<FlatArrayType>(std::vector{mkPtr<ScalarArchetype>(1)});
    BOOST_CHECK_EQUAL(*archetype_cast<TrueScalarType>(arr), *sc);
}

BOOST_AUTO_TEST_CASE(Test_Casts_ArchetypeCastComplexArrayToTrueScalar) {
    auto sc = mkPtr<TrueScalarType>(1);
    auto arr = mkPtr<ComplexArrayType>(std::vector{std::static_pointer_cast<AnyArchetype>(mkPtr<ScalarArchetype>(1))});
    BOOST_CHECK_EQUAL(*archetype_cast<TrueScalarType>(arr), *sc);
}

BOOST_AUTO_TEST_CASE(Test_Casts_ArchetypeCastFlatArrayToCharScalar) {
    auto sc = mkPtr<CharacterScalarType>(1);
    auto arr = mkPtr<FlatArrayType>(std::vector{mkPtr<ScalarArchetype>(1)});
    BOOST_CHECK_EQUAL(*archetype_cast<CharacterScalarType>(arr), *sc);
}

BOOST_AUTO_TEST_CASE(Test_Casts_ArchetypeCastComplexArrayToCharScalar) {
    auto sc = mkPtr<CharacterScalarType>(1);
    auto arr = mkPtr<ComplexArrayType>(std::vector{std::static_pointer_cast<AnyArchetype>(mkPtr<ScalarArchetype>(1))});
    BOOST_CHECK_EQUAL(*archetype_cast<CharacterScalarType>(arr), *sc);
}

// Types
BOOST_AUTO_TEST_CASE(Test_Casts_ScalarCastFromTrueToCharacter) {
    TrueScalarType tru((int) 'a');
    CharacterScalarType khar((int) 'a');
    BOOST_REQUIRE_NE(tru, khar);
    BOOST_CHECK_EQUAL((CharacterScalarType) Casts::scalar_cast<TrueScalarType>(tru), khar);
}

BOOST_AUTO_TEST_CASE(Test_Casts_ScalarCastFromCharacterToTrue) {
    TrueScalarType tru((int) 'a');
    CharacterScalarType khar((int) 'a');
    BOOST_REQUIRE_NE(tru, khar);
    BOOST_CHECK_EQUAL(tru, (TrueScalarType) Casts::scalar_cast<CharacterScalarType>(khar));
}

BOOST_AUTO_TEST_CASE(Test_Casts_ArrayCastFromFlatToComplex) {
    FlatArrayType flat{mkPtr<TrueScalarType>(4)};
    ComplexArrayType cmpx{mkPtr<TrueScalarType>(4)};
    BOOST_REQUIRE_NE(flat, cmpx);
    BOOST_CHECK_EQUAL((ComplexArrayType) Casts::array_cast<FlatArrayType>(flat), cmpx);
}

BOOST_AUTO_TEST_CASE(Test_Casts_ArrayCastFromComplexToFlatEasy) {
    FlatArrayType flat{mkPtr<TrueScalarType>(4)};
    ComplexArrayType cmpx{mkPtr<TrueScalarType>(4)};
    BOOST_REQUIRE_NE(flat, cmpx);
    BOOST_CHECK_EQUAL((FlatArrayType) Casts::array_cast<ComplexArrayType>(cmpx), flat);
}

BOOST_AUTO_TEST_CASE(Test_Casts_ArrayCastFromComplexToFlatHard) {
    FlatArrayType flat{mkPtr<TrueScalarType>(4)};
    ComplexArrayType cmpx{mkPtr<FlatArrayType>(std::vector{
            mkPtr<ScalarArchetype>(1), mkPtr<ScalarArchetype>(1),
            mkPtr<ScalarArchetype>(1), mkPtr<ScalarArchetype>(1)
    })};
    BOOST_REQUIRE_NE(flat, cmpx);
    BOOST_CHECK_EQUAL((FlatArrayType) Casts::array_cast<ComplexArrayType>(cmpx), flat);
}

#pragma clang diagnostic pop

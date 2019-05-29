//
// Created by bodand on 2019. 05. 27..
//

#pragma once

#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemberFunctionCanBeStaticInspection"
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <boost/test/included/unit_test.hpp>

#include "../types/archetypes/ScalarArchetype.hpp"
#include "../types/ImplementationTypes.hpp"

using namespace LibCqt;

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_Constructible) {
    auto sc = mkRaw<ScalarArchetype>();
    BOOST_CHECK_NE(sc, nullptr);
    rmRaw(sc);
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_IsConstructibleFromValue) {
    auto sc = mkRaw<ScalarArchetype>(4);
    BOOST_CHECK_NE(sc, nullptr);
    BOOST_CHECK_EQUAL(sc->getValue(), 4);
    rmRaw(sc);
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_CopyConstructable) {
    auto sc1 = mkRaw<ScalarArchetype>(5);
    BOOST_REQUIRE_NE(sc1, nullptr);
    auto sc2 = mkRaw<ScalarArchetype>(*sc1);
    BOOST_REQUIRE_NE(sc2, nullptr);
    BOOST_CHECK_EQUAL(*sc1, *sc2);
    BOOST_CHECK_EQUAL(*sc1, 5);
    BOOST_CHECK_EQUAL(*sc2, 5);
    rmRaw(sc1);
    rmRaw(sc2);
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_MoveConstructable) {
    auto sc1 = mkRaw<ScalarArchetype>(5);
    BOOST_REQUIRE_NE(sc1, nullptr);
    BOOST_REQUIRE_EQUAL(*sc1, 5);
    auto sc2 = mkRaw<ScalarArchetype>(std::move(*sc1));
    BOOST_REQUIRE_NE(sc2, nullptr);
    BOOST_CHECK_EQUAL(*sc2, 5);
    rmRaw(sc1);
    rmRaw(sc2);
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_CopyAssignable) {
    auto sc1 = mkRaw<ScalarArchetype>(5);
    BOOST_REQUIRE_NE(sc1, nullptr);
    auto sc2 = *sc1;
    BOOST_CHECK_EQUAL(*sc1, sc2);
    BOOST_CHECK_EQUAL(*sc1, 5);
    BOOST_CHECK_EQUAL(sc2, 5);
    rmRaw(sc1);
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_MoveAssignable) {
    auto sc1 = mkRaw<ScalarArchetype>(5);
    BOOST_REQUIRE_NE(sc1, nullptr);
    BOOST_REQUIRE_EQUAL(*sc1, 5);
    auto sc2 = std::move(*sc1);
    BOOST_CHECK_EQUAL(sc2, 5);
    rmRaw(sc1);
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_ConstructibleFromPtrToOther) {
    auto sc1 = mkPtr<ScalarArchetype>(5);
    auto sc2 = mkPtr<ScalarArchetype>(sc1);
    BOOST_CHECK_EQUAL(*sc1, 5);
    BOOST_CHECK_EQUAL(*sc2, 5);
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_Equality) {
    ScalarArchetype sc1(5);
    ScalarArchetype sc2(5);
    BOOST_CHECK_EQUAL(sc1, sc2);
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_InEquality) {
    ScalarArchetype sc1;
    ScalarArchetype sc2(5);
    BOOST_CHECK_NE(sc1, sc2);
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_GT) {
    ScalarArchetype sc1(3);
    ScalarArchetype sc2(5);
    BOOST_CHECK_GT(sc2, sc1);
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_LT) {
    ScalarArchetype sc1(5);
    ScalarArchetype sc2(3);
    BOOST_CHECK_LT(sc2, sc1);
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_GE) {
    ScalarArchetype sc1(3);
    ScalarArchetype sc2(5);
    ScalarArchetype sc3(5);
    BOOST_CHECK_GE(sc2, sc1);
    BOOST_CHECK_GE(sc3, sc2);
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_LE) {
    ScalarArchetype sc1(3);
    ScalarArchetype sc2(5);
    ScalarArchetype sc3(5);
    BOOST_CHECK_LE(sc1, sc2);
    BOOST_CHECK_LE(sc3, sc2);
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_EqualityWithDouble) {
    ScalarArchetype sc(5);
    BOOST_CHECK_EQUAL(sc, 5);
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_InEqualityWithDouble) {
    ScalarArchetype sc;
    BOOST_CHECK_NE(sc, 2);
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_GTWithDouble) {
    ScalarArchetype sc(3);
    BOOST_CHECK_GT(sc, 1);
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_LTWithDouble) {
    ScalarArchetype sc(5);
    BOOST_CHECK_LT(sc, 8);
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_GEWithDouble) {
    ScalarArchetype sc(5);
    BOOST_CHECK_GE(sc, 3);
    BOOST_CHECK_GE(sc, 5);
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_LEWithDouble) {
    ScalarArchetype sc(5);
    BOOST_CHECK_LE(sc, 7);
    BOOST_CHECK_LE(sc, 5);
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_AsStringInt) {
    ScalarArchetype sc(5);
#ifdef _CQT_WINDOWS
    BOOST_CHECK(sc.asString() == CQT_STRING("5"));
#else
    BOOST_CHECK_EQUAL(sc.asString(), CQT_STRING("5"));
#endif
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_AsStringDouble) {
    ScalarArchetype sc(5.45);
#ifdef _CQT_WINDOWS
    BOOST_CHECK(sc.asString() == CQT_STRING("5.45"));
#else
    BOOST_CHECK_EQUAL(sc.asString(), CQT_STRING("5.45"));
#endif
}

BOOST_AUTO_TEST_CASE(Test_ScalarArchetype_GetScalarType) {
    ScalarArchetype sc(5);
    BOOST_CHECK_EQUAL(sc.getScalarType(), scalarAnyScalar);
}

#pragma clang diagnostic pop

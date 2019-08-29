//
// Created by  on 2019. 05. 22..
//

#pragma once

#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemberFunctionCanBeStaticInspection"
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <boost/test/included/unit_test.hpp>

#include "../src/cqt.hpp"
#include "../types/ImplementationTypes.hpp"
#include "../types/archetypes/AnyArchetype.hpp"

using namespace LibCqt;

BOOST_AUTO_TEST_CASE(Test_AnyArchetype_IsConstructible) {
    auto any = mkRaw<AnyArchetype>();
    BOOST_CHECK_NE(any, nullptr);
    rmRaw(any);
}

BOOST_AUTO_TEST_CASE(Test_AnyArchetype_IsConstructibleWithType) {
    auto any = mkRaw<AnyArchetype>(archArray);
    BOOST_CHECK_NE(any, nullptr);
    rmRaw(any);
}

BOOST_AUTO_TEST_CASE(Test_AnyArchetype_AsStringReturnsQuoteSensibleString) {
    auto any = mkRaw<AnyArchetype>();
    BOOST_REQUIRE_NE(any, nullptr);
    auto str = any->asString();
    BOOST_CHECK(str ==
                CQT_STRING("(>_<´) The printing of a decayed getScalarType is undefined behaviour you utter failure. "
                           "Imagine the shit you'd be in if I weren't here to cover your lazy to typecheck ass. "
                           "This could result in immediate termination with less powerful and caring compilers."));
    rmRaw(any);
}

BOOST_AUTO_TEST_CASE(Test_AnyArchetype_CopyConstructible) {
    AnyArchetype any1(archArray);
    BOOST_REQUIRE_EQUAL(any1.getCurrentType(), archArray);
    AnyArchetype any2(any1);
    BOOST_CHECK_EQUAL(any2.getCurrentType(), archArray);
}

BOOST_AUTO_TEST_CASE(Test_AnyArchetype_CopyAssignable) {
    AnyArchetype any1(archArray);
    BOOST_REQUIRE_EQUAL(any1.getCurrentType(), archArray);
    AnyArchetype any2(archHash);
    BOOST_REQUIRE_EQUAL(any2.getCurrentType(), archHash);
    any2 = any1;
    BOOST_CHECK_EQUAL(any2.getCurrentType(), archArray);
}

BOOST_AUTO_TEST_CASE(Test_AnyArchetype_MoveConstructible) {
    AnyArchetype any1(archArray);
    BOOST_REQUIRE_EQUAL(any1.getCurrentType(), archArray);
    AnyArchetype any2(std::move(any1));
    BOOST_CHECK_EQUAL(any2.getCurrentType(), archArray);
}

BOOST_AUTO_TEST_CASE(Test_AnyArchetype_MoveAssignable) {
    AnyArchetype any1(archArray);
    BOOST_REQUIRE_EQUAL(any1.getCurrentType(), archArray);
    AnyArchetype any2(archHash);
    BOOST_REQUIRE_EQUAL(any2.getCurrentType(), archHash);
    any2 = std::move(any1);
    BOOST_CHECK_EQUAL(any2.getCurrentType(), archArray);
}

BOOST_AUTO_TEST_CASE(Test_AnyArchetype_EqualityOperatorWorks) {
    AnyArchetype any1(archArray);
    BOOST_REQUIRE_EQUAL(any1.getCurrentType(), archArray);
    AnyArchetype any2(archArray);
    BOOST_REQUIRE_EQUAL(any2.getCurrentType(), archArray);
    BOOST_CHECK_EQUAL(any1, any2);
}

BOOST_AUTO_TEST_CASE(Test_AnyArchetype_InequalityOperatorWorks) {
    AnyArchetype any1(archArray);
    BOOST_REQUIRE_EQUAL(any1.getCurrentType(), archArray);
    AnyArchetype any2(archHash);
    BOOST_REQUIRE_EQUAL(any2.getCurrentType(), archHash);
    BOOST_CHECK_NE(any1, any2);
}

#pragma clang diagnostic pop

//
// Created by bodand on 2019-06-30.
//

#pragma once

#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemberFunctionCanBeStaticInspection"
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <boost/test/included/unit_test.hpp>

#include <limits>
#include <boost/math/special_functions/next.hpp>
#include "../src/Utils.hpp"

using namespace LibStarch::Utils;
using boost::math::float_next;

BOOST_AUTO_TEST_CASE(Test_Utils_EQ_true) {
    double a = 645.5;
    double b = 645.5;

    BOOST_CHECK(deq(a, b));
}

BOOST_AUTO_TEST_CASE(Test_Utils_EQ_false) {
    double a = 645.5;
    double b = 645.7;

    BOOST_CHECK(!deq(a, b));
}

BOOST_AUTO_TEST_CASE(Test_Utils_EQ_1_epsilon_diff_false) {
    double a = 1;
    double b = a + std::numeric_limits<double>::epsilon();

    BOOST_CHECK(!deq(a, b));
}

BOOST_AUTO_TEST_CASE(Test_Utils_EQ_next_float_diff_false) {
    double a = 645.5;
    double b = float_next(a);

    BOOST_CHECK(!deq(a, b));
}

BOOST_AUTO_TEST_CASE(Test_Utils_NE_false) {
    double a = 645.5;
    double b = 645.5;

    BOOST_CHECK(!dne(a, b));
}

BOOST_AUTO_TEST_CASE(Test_Utils_NE_true) {
    double a = 645.5;
    double b = 645.7;

    BOOST_CHECK(dne(a, b));
}

BOOST_AUTO_TEST_CASE(Test_Utils_NE_1_epsilon_diff_true) {
    double a = 1;
    double b = a + std::numeric_limits<double>::epsilon();

    BOOST_CHECK(dne(a, b));
}

BOOST_AUTO_TEST_CASE(Test_Utils_NE_next_float_diff_true) {
    double a = 645.5;
    double b = float_next(a);

    BOOST_CHECK(dne(a, b));
}

BOOST_AUTO_TEST_CASE(Test_Utils_GT_false) {
    double a = 645.5;
    double b = 645.5;

    BOOST_CHECK(!dgt(a, b));
}

BOOST_AUTO_TEST_CASE(Test_Utils_GT_true) {
    double a = 645.7;
    double b = 645.5;

    BOOST_CHECK(dgt(a, b));//a > b
}

BOOST_AUTO_TEST_CASE(Test_Utils_GT_1_epsilon_diff_true) {
    double a = 1;
    double b = a + std::numeric_limits<double>::epsilon();

    BOOST_CHECK(dgt(b, a));
}

BOOST_AUTO_TEST_CASE(Test_Utils_GT_next_float_diff_true) {
    double a = 645.5;
    double b = float_next(a);

    BOOST_CHECK(dgt(b, a));
}

BOOST_AUTO_TEST_CASE(Test_Utils_LT_false) {
    double a = 645.5;
    double b = 645.5;

    BOOST_CHECK(!dlt(a, b));
}

BOOST_AUTO_TEST_CASE(Test_Utils_LT_true) {
    double a = 645.5;
    double b = 645.7;

    BOOST_CHECK(dlt(a, b));
}

BOOST_AUTO_TEST_CASE(Test_Utils_LT_1_epsilon_diff_true) {
    double a = 1;
    double b = a + std::numeric_limits<double>::epsilon();

    BOOST_CHECK(dlt(a, b));
}

BOOST_AUTO_TEST_CASE(Test_Utils_LT_next_float_diff_true) {
    double a = 645.5;
    double b = float_next(a);

    BOOST_CHECK(dlt(a, b));
}

BOOST_AUTO_TEST_CASE(Test_Utils_GE_false) {
    double a = 645.5;
    double b = 645.3;

    BOOST_CHECK(!dge(b, a));
}

BOOST_AUTO_TEST_CASE(Test_Utils_GE_true) {
    double a = 645.5;
    double b = 645.5;
    double c = 645.7;

    BOOST_CHECK(dge(b, a));
    BOOST_CHECK(dge(c, a));
}

BOOST_AUTO_TEST_CASE(Test_Utils_GE_1_epsilon_diff_true) {
    double a = 1;
    double b = a + std::numeric_limits<double>::epsilon();
    double c = a + std::numeric_limits<double>::epsilon();

    BOOST_CHECK(dge(b, a));
    BOOST_CHECK(dge(b, c));
}

BOOST_AUTO_TEST_CASE(Test_Utils_GE_next_float_diff_true) {
    double a = 645.5;
    double b = float_next(a);
    double c = float_next(a);

    BOOST_CHECK(dge(b, a));
    BOOST_CHECK(dge(b, c));
}

BOOST_AUTO_TEST_CASE(Test_Utils_LE_false) {
    double a = 645.5;
    double b = 645.3;

    BOOST_CHECK(!dle(a, b));
}

BOOST_AUTO_TEST_CASE(Test_Utils_LE_true) {
    double a = 645.5;
    double b = 645.5;
    double c = 645.7;

    BOOST_CHECK(dle(a, b)); // a <= b
    BOOST_CHECK(dle(a, c)); // a <= c
}

BOOST_AUTO_TEST_CASE(Test_Utils_LE_1_epsilon_diff_true) {
    double a = 1;
    double b = a + std::numeric_limits<double>::epsilon();
    double c = a + std::numeric_limits<double>::epsilon();

    BOOST_CHECK(dle(a, b));
    BOOST_CHECK(dle(b, c));
}

BOOST_AUTO_TEST_CASE(Test_Utils_LE_next_float_diff_true) {
    double a = 645.5;
    double b = float_next(a);
    double c = float_next(a);

    BOOST_CHECK(dle(a, b));
    BOOST_CHECK(dle(b, c));
}


#pragma clang diagnostic pop

//
// Created by bodand on 2019-06-29.
//

#pragma once

#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemberFunctionCanBeStaticInspection"
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <boost/test/included/unit_test.hpp>

#include "../cexpr/impl/CExpressionImpl.hpp"
#include "../cexpr/impl/AdditionExpressionImpl.hpp"
#include "../cexpr/impl/SubtractionExpressionImpl.hpp"
#include "../cexpr/impl/MultiplicationExpressionImpl.hpp"
#include "../cexpr/impl/DivisionExpressionImpl.hpp"
#include "../cexpr/impl/ModuloExpressionImpl.hpp"
#include "../cexpr/impl/EqualityExpressionImpl.hpp"
#include "../cexpr/impl/InequalityExpressionImpl.hpp"
#include "../cexpr/impl/LessOrEqualExpressionImpl.hpp"
#include "../cexpr/impl/GreaterThanExpressionImpl.hpp"
#include "../cexpr/impl/LessThanExpressionImpl.hpp"
#include "../cexpr/impl/GreaterOrEqualExpressionImpl.hpp"
#include "../cexpr/impl/ValueExpressionImpl.hpp"
#include "../cexpr/impl/NegateExpressionImpl.hpp"
#include "../cexpr/impl/TernaryExpressionImpl.hpp"

using namespace LibStarch;

//BOOST_AUTO_TEST_CASE(Test_CExpression_CtorWorks) {
//    CExpression expr(ValNumber(1), ValText("2"), CondNode());
//    BOOST_CHECK_NE(&expr, nullptr);
//}

BOOST_AUTO_TEST_CASE(Test_CExpression_PlusExpr) {
    AdditionExpressionImpl expr(ValNumber(1), ValNumber(2));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 3.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_MinusExpr) {
    SubtractionExpressionImpl expr(ValNumber(5.4), ValNumber(.2));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 5.2);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_TimesExpr) {
    MultiplicationExpressionImpl expr(ValNumber(5.4), ValText("4"));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 21.6);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_DivExpr, *boost::unit_test::tolerance(.00001)) {
    DivisionExpressionImpl expr(ValNumber(5.4), ValText("4"));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1.35);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_ModExpr, *boost::unit_test::tolerance(.00001)) {
    ModuloExpressionImpl expr(ValNumber(5.4), ValText("4"));
    double res = std::fmod(5.4, 4);

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), res);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_EqExpr_false) {
    EqualityExpressionImpl expr(ValNumber(1), ValNumber(2));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 0.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_EqExpr_true) {
    EqualityExpressionImpl expr(ValNumber(1), ValNumber(1));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_NeExpr_false) {
    InequalityExpressionImpl expr(ValNumber(1), ValNumber(1));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 0.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_NeExpr_true) {
    InequalityExpressionImpl expr(ValNumber(1), ValNumber(2));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_GtExpr_false) {
    GreaterThanExpressionImpl expr(ValNumber(1), ValNumber(2));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 0.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_GtExpr_true) {
    GreaterThanExpressionImpl expr(ValNumber(2), ValNumber(1));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_LtExpr_false) {
    LessThanExpressionImpl expr(ValNumber(2), ValNumber(1));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 0.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_LtExpr_true) {
    LessThanExpressionImpl expr(ValNumber(1), ValNumber(2));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_GeExpr_false) {
    GreaterOrEqualExpressionImpl expr(ValNumber(1), ValNumber(2));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 0.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_GeExpr_true_eq) {
    GreaterOrEqualExpressionImpl expr(ValNumber(1), ValNumber(1));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_GeExpr_true_gt) {
    GreaterOrEqualExpressionImpl expr(ValNumber(2), ValNumber(1));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_LeExpr_false) {
    LessOrEqualExpressionImpl expr(ValNumber(2), ValNumber(1));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 0.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_LeExpr_true_eq) {
    LessOrEqualExpressionImpl expr(ValNumber(1), ValNumber(1));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_LeExpr_true_lt) {
    LessOrEqualExpressionImpl expr(ValNumber(1), ValNumber(2));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_ValueExpr) {
    ValueExpressionImpl expr(ValNumber(42));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 42.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_NegateExpr) {
    NegateExpressionImpl expr(ValNumber(42));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), -42.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_TernaryEvalsTrue) {
    TernaryExpressionImpl expr(ValNumber(1), ValNumber(2), std::optional(CondNode(ValueExpressionImpl(ValNumber(1)))));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_TernaryEvalsFalse) {
    TernaryExpressionImpl expr(ValNumber(1), ValNumber(2), std::optional(CondNode(ValueExpressionImpl(ValNumber(0)))));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 2);
}

#pragma clang diagnostic pop

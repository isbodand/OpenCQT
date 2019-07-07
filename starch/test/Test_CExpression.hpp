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
#include "../cexpr/SubtractionExpression.hpp"
#include "../cexpr/MultiplicationExpression.hpp"
#include "../cexpr/DivisionExpression.hpp"
#include "../cexpr/ModuloExpression.hpp"
#include "../cexpr/EqualityExpression.hpp"
#include "../cexpr/InequalityExpression.hpp"
#include "../cexpr/LessOrEqualExpression.hpp"
#include "../cexpr/GreaterThanExpression.hpp"
#include "../cexpr/LessThanExpression.hpp"
#include "../cexpr/GreaterOrEqualExpression.hpp"
#include "../cexpr/ValueExpression.hpp"
#include "../cexpr/NegateExpression.hpp"
#include "../cexpr/TernaryExpression.hpp"

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
    SubtractionExpression expr(ValNumber(5.4), ValNumber(.2));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 5.2);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_TimesExpr) {
    MultiplicationExpression expr(ValNumber(5.4), ValText("4"));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 21.6);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_DivExpr, *boost::unit_test::tolerance(.00001)) {
    DivisionExpression expr(ValNumber(5.4), ValText("4"));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1.35);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_ModExpr, *boost::unit_test::tolerance(.00001)) {
    ModuloExpression expr(ValNumber(5.4), ValText("4"));
    double res = std::fmod(5.4, 4);

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), res);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_EqExpr_false) {
    EqualityExpression expr(ValNumber(1), ValNumber(2));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 0.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_EqExpr_true) {
    EqualityExpression expr(ValNumber(1), ValNumber(1));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_NeExpr_false) {
    InequalityExpression expr(ValNumber(1), ValNumber(1));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 0.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_NeExpr_true) {
    InequalityExpression expr(ValNumber(1), ValNumber(2));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_GtExpr_false) {
    GreaterThanExpression expr(ValNumber(1), ValNumber(2));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 0.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_GtExpr_true) {
    GreaterThanExpression expr(ValNumber(2), ValNumber(1));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_LtExpr_false) {
    LessThanExpression expr(ValNumber(2), ValNumber(1));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 0.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_LtExpr_true) {
    LessThanExpression expr(ValNumber(1), ValNumber(2));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_GeExpr_false) {
    GreaterOrEqualExpression expr(ValNumber(1), ValNumber(2));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 0.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_GeExpr_true_eq) {
    GreaterOrEqualExpression expr(ValNumber(1), ValNumber(1));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_GeExpr_true_gt) {
    GreaterOrEqualExpression expr(ValNumber(2), ValNumber(1));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_LeExpr_false) {
    LessOrEqualExpression expr(ValNumber(2), ValNumber(1));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 0.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_LeExpr_true_eq) {
    LessOrEqualExpression expr(ValNumber(1), ValNumber(1));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_LeExpr_true_lt) {
    LessOrEqualExpression expr(ValNumber(1), ValNumber(2));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_ValueExpr) {
    ValueExpression expr(ValNumber(42));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 42.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_NegateExpr) {
    NegateExpression expr(ValNumber(42));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), -42.0);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_TernaryEvalsTrue) {
    TernaryExpression expr(ValNumber(1), ValNumber(2), std::optional(CondNode(ValueExpression(ValNumber(1)))));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 1);
}

BOOST_AUTO_TEST_CASE(Test_CExpression_TernaryEvalsFalse) {
    TernaryExpression expr(ValNumber(1), ValNumber(2), std::optional(CondNode(ValueExpression(ValNumber(0)))));

    BOOST_REQUIRE_NE(&expr, nullptr);
    BOOST_CHECK_EQUAL(expr.eval(), 2);
}

#pragma clang diagnostic pop

//
// Created by bodand on 2019-06-29.
//

#pragma once

#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemberFunctionCanBeStaticInspection"
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <boost/test/included/unit_test.hpp>
#include "../val_subtrees/ValNode.hpp"
#include "../val_subtrees/ValId.hpp"
#include "../val_subtrees/ValNumber.hpp"
#include "../val_subtrees/ValText.hpp"
#include "../cexpr/impl/AdditionExpressionImpl.hpp"
#include "../val_subtrees/ValExpr.hpp"
#include "../cexpr/ValueExpression.hpp"

#include <string>

using namespace LibStarch;

BOOST_AUTO_TEST_CASE(Test_ValSubtree_ValIdCtorWorks) {
    ValID id1 = "say";
    ValID id2 = std::string("inform");
    ValID id3("warn");
    ValID id4(std::string("die"));

    BOOST_CHECK_EQUAL(id1.getIdName(), "say");
    BOOST_CHECK_EQUAL(id2.getIdName(), "inform");
    BOOST_CHECK_EQUAL(id3.getIdName(), "warn");
    BOOST_CHECK_EQUAL(id4.getIdName(), "die");
}

BOOST_AUTO_TEST_CASE(Test_ValSubtree_ValTextCtorWorks) {
    ValText txt1 = "4";
    ValText txt2 = std::string("42");
    ValText txt3("21.85");
    ValText txt4(std::string("8994651 wasp"));

    BOOST_CHECK_EQUAL(txt1.getValue(), "4");
    BOOST_CHECK_EQUAL(txt2.getValue(), "42");
    BOOST_CHECK_EQUAL(txt3.getValue(), "21.85");
    BOOST_CHECK_EQUAL(txt4.getValue(), "8994651 wasp");
}

BOOST_AUTO_TEST_CASE(Test_ValSubtree_ValNumberCtorWorks) {
    ValNumber num1 = 4;
    ValNumber num2(21.85);

    BOOST_CHECK_EQUAL(num1.getValue(), 4);
    BOOST_CHECK_EQUAL(num2.getValue(), 21.85);
}

BOOST_AUTO_TEST_CASE(Test_ValSubtree_ValNodeEvaluationsWork) {
    ValNumber num = 54;
    ValID id = "fug";
    ValText txt = "45.5289";

    BOOST_CHECK_EQUAL(num.eval(), 54);
    BOOST_CHECK_EQUAL(id.eval(), 0);
    BOOST_CHECK_EQUAL(txt.eval(), 45.5289);
}

BOOST_AUTO_TEST_CASE(Test_ValSubtree_ValExprEvaluationWorks) {
    ValExpr exp(AdditionExpressionImpl(ValNumber(1), ValText("2")));

    BOOST_CHECK_EQUAL(exp.eval(), 3);
}

BOOST_AUTO_TEST_CASE(Test_ValSubtree_ComplexishExpressionsEvaluate) {
    ValExpr exp(AdditionExpressionImpl(ValExpr(AdditionExpressionImpl(ValNumber(1), ValText("1"))), ValNumber(2)));

    BOOST_CHECK_EQUAL(exp.eval(), 4);
}

BOOST_AUTO_TEST_CASE(Test_ValSubtree_ValIdPrintingWorks) {
    std::stringstream ss;
    ValID id = "die";
    ss << id;
    std::string str = ss.str();
    BOOST_CHECK_EQUAL(str, "[ValID \"die\"]");
}

BOOST_AUTO_TEST_CASE(Test_ValSubtree_ValTextPrintingWorks) {
    std::stringstream ss;
    ValText txt = "42";
    ss << txt;
    std::string str = ss.str();
    BOOST_CHECK_EQUAL(str, "[ValText \"42\"]");
}

BOOST_AUTO_TEST_CASE(Test_ValSubtree_ValNumberPrintingWorks) {
    std::stringstream ss;
    ValNumber txt = 42;
    ss << txt;
    std::string str = ss.str();
    BOOST_CHECK_EQUAL(str, "[ValNumber 42]");
}

BOOST_AUTO_TEST_CASE(Test_ValSubtree_ValExprPrintingWorks) {
    std::stringstream ss;
    ValExpr val(AdditionExpressionImpl(ValNumber(1), ValNumber(1)));
    ss << val;
    std::string str = ss.str();
    BOOST_CHECK_EQUAL(str, "[ValExpr(2): [Plus(2) lhs: [ValNumber 1] rhs: [ValNumber 1] cond: [empty]]]");
}

BOOST_AUTO_TEST_CASE(Test_ValSubtree_AllValNodesAreCopyable) {
    ValNumber num = 54;
    ValID id = "fug";
    ValText txt = "45.5289";
    ValExpr exp(AdditionExpressionImpl(ValNumber(1), ValText("2")));

    ValNumber num2(num);
    ValNumber num2o = num;
    ValID id2(id);
    ValID id2o = id;
    ValText txt2(txt);
    ValText txt2o = txt;
    ValExpr exp2(exp);
    ValExpr exp2o = exp;
    BOOST_CHECK_MESSAGE(true, "All ValNodes are copyable");
}

#pragma clang diagnostic pop

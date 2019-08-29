//
// Created by bodand on 2019. 05. 22..
//

#pragma once

#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemberFunctionCanBeStaticInspection"
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <boost/test/included/unit_test.hpp>

#include "../versioning.hpp"
#include "../src/cqt.hpp"

using namespace LibCqt;

BOOST_AUTO_TEST_CASE(Test_Version) {
#if defined(_WIN32) || defined(_WIN64)
    BOOST_CHECK(getVersion() == L"0.1-β");
#else
    BOOST_CHECK(getVersion() == "0.1-β");
#endif
}

BOOST_AUTO_TEST_CASE(Test_Version_WithCQT_STRINGMacro) {
    BOOST_CHECK(getVersion() == CQT_STRING("0.1-β"));
}

#pragma clang diagnostic pop

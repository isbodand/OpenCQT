//
// Created by bodand on 2019-05-29.
//

#pragma once

#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemberFunctionCanBeStaticInspection"
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(Test_Testing) {
    BOOST_CHECK_MESSAGE(true, "Is your setup of Boost.Test broken?");
}

#pragma clang diagnostic pop

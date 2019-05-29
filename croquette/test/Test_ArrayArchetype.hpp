//
// Created by bodand on 2019. 05. 22..
//

#pragma once

#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemberFunctionCanBeStaticInspection"
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <boost/test/included/unit_test.hpp>

#include "../cqt.hpp"
#include "../types/ImplementationTypes.hpp"
#include "../types/archetypes/ArrayArchetype.hpp"
#include "../types/archetypes/ScalarArchetype.hpp"
#include "../types/user_types/TrueScalarType.hpp"
#include "../types/user_types/CharacterScalarType.hpp"

using namespace LibCqt;

BOOST_AUTO_TEST_CASE(Test_ArrayArchetype_IsConstructible) {
    auto array = mkRaw<ArrayArchetype<ScalarArchetype>>();
    BOOST_CHECK_NE(array, nullptr);
    rmRaw(array);
}

BOOST_AUTO_TEST_CASE(Test_ArrayArchetype_IsInitializerListConstructible) {
    auto array = new ArrayArchetype{mkPtr<TrueScalarType>(1),
                                    mkPtr<TrueScalarType>(2)};
    BOOST_CHECK_NE(array, nullptr);
    for (const auto& cell : array->getCells()) {
        BOOST_CHECK_NE(cell.get(), nullptr);
    }
    rmRaw(array);
}

BOOST_AUTO_TEST_CASE(Test_ArrayArchetype_CopyConstructible) {
    ArrayArchetype array1{mkPtr<TrueScalarType>(1)};
    BOOST_REQUIRE_EQUAL(array1.getCurrentType(), archArray);
    BOOST_REQUIRE_EQUAL(array1.getCells().size(), 1);
    ArrayArchetype array2(array1);
    BOOST_REQUIRE_EQUAL(array2.getCurrentType(), archArray);
    BOOST_REQUIRE_EQUAL(array2.getCells().size(), 1);
}

BOOST_AUTO_TEST_CASE(Test_ArrayArchetype_CopyAssignable) {
    ArrayArchetype array1{mkPtr<TrueScalarType>(1)};
    BOOST_REQUIRE_EQUAL(array1.getCurrentType(), archArray);
    BOOST_REQUIRE_EQUAL(array1.getCells().size(), 1);
    ArrayArchetype array2{mkPtr<TrueScalarType>(2), mkPtr<TrueScalarType>(2)};
    BOOST_REQUIRE_EQUAL(array2.getCurrentType(), archArray);
    BOOST_REQUIRE_EQUAL(array2.getCells().size(), 2);
    array2 = array1;
    BOOST_REQUIRE_EQUAL(array2.getCurrentType(), archArray);
    BOOST_CHECK_EQUAL(array2.getCells().size(), 1);
}

BOOST_AUTO_TEST_CASE(Test_ArrayArchetype_MoveConstructible) {
    ArrayArchetype array1{mkPtr<TrueScalarType>(1)};
    BOOST_REQUIRE_EQUAL(array1.getCurrentType(), archArray);
    BOOST_REQUIRE_EQUAL(array1.getCells().size(), 1);
    ArrayArchetype array2(std::move(array1));
    BOOST_REQUIRE_EQUAL(array2.getCurrentType(), archArray);
    BOOST_CHECK_EQUAL(array2.getCells().size(), 1);
}

BOOST_AUTO_TEST_CASE(Test_ArrayArchetype_MoveAssignable) {
    ArrayArchetype array1{mkPtr<TrueScalarType>(1)};
    BOOST_REQUIRE_EQUAL(array1.getCurrentType(), archArray);
    BOOST_REQUIRE_EQUAL(array1.getCells().size(), 1);
    ArrayArchetype array2{mkPtr<TrueScalarType>(2), mkPtr<TrueScalarType>(2)};
    BOOST_REQUIRE_EQUAL(array2.getCurrentType(), archArray);
    BOOST_REQUIRE_EQUAL(array2.getCells().size(), 2);
    array2 = std::move(array1);
    BOOST_REQUIRE_EQUAL(array2.getCurrentType(), archArray);
    BOOST_CHECK_EQUAL(array2.getCells().size(), 1);
}

BOOST_AUTO_TEST_CASE(Test_ArrayArchetype_ConstructibleFromShdPtr) {
    auto array1 = mkPtr<ArrayArchetype<>>();
    auto array2 = mkRaw<ArrayArchetype<>>(array1);
    BOOST_CHECK_NE(array2, nullptr);
}

BOOST_AUTO_TEST_CASE(Test_ArrayArchetype_BracketoperatorReadWorks) {
    ArrayArchetype<> array1{mkPtr<TrueScalarType>(1), mkPtr<TrueScalarType>(2)};
    BOOST_CHECK_EQUAL(*array1[1], TrueScalarType(2));
}

BOOST_AUTO_TEST_CASE(Test_ArrayArchetype_BracketoperatorWriteWorks) {
    ArrayArchetype<> array1{mkPtr<TrueScalarType>(1), mkPtr<TrueScalarType>(2)};
    array1[1] = mkPtr<TrueScalarType>(3);
    BOOST_CHECK_EQUAL(*array1[1], TrueScalarType(3));
}

BOOST_AUTO_TEST_CASE(Test_ArrayArchetype_EqualityWorks) {
    ArrayArchetype<> array1{mkPtr<TrueScalarType>(1), mkPtr<TrueScalarType>(1)};
    ArrayArchetype<> array2{mkPtr<TrueScalarType>(1), mkPtr<TrueScalarType>(1)};
    BOOST_CHECK_EQUAL(array1, array2);
}

BOOST_AUTO_TEST_CASE(Test_ArrayArchetype_InequalityWorks) {
    ArrayArchetype<> array1{mkPtr<TrueScalarType>(1), mkPtr<TrueScalarType>(2)};
    ArrayArchetype<> array2{mkPtr<TrueScalarType>(2), mkPtr<TrueScalarType>(2)};
    BOOST_CHECK_NE(array1, array2);
}

BOOST_AUTO_TEST_CASE(Test_ArrayArchetype_SizeReturnsCorrectSize) {
    ArrayArchetype<> array1;
    ArrayArchetype<> array2{mkPtr<TrueScalarType>(1), mkPtr<TrueScalarType>(2)};
    BOOST_CHECK_EQUAL(array1.size(), 0);
    BOOST_CHECK_EQUAL(array2.size(), 2);
}

BOOST_AUTO_TEST_CASE(Test_ArrayArchetype_MakeCellCreatesCell) {
    ArrayArchetype<> array;
    array.makeCell();
    BOOST_CHECK_EQUAL(array.size(), 1);
    BOOST_CHECK_EQUAL(*array[0], 0);
}

BOOST_AUTO_TEST_CASE(Test_ArrayArchetype_ParameterizedMakeCellCreatesCellCorrectly) {
    ArrayArchetype<> array;
    array.makeCell(4);
    BOOST_CHECK_EQUAL(array.size(), 1);
    BOOST_CHECK_EQUAL(*array[0], 4);
}

BOOST_AUTO_TEST_CASE(Test_ArrayArchetype_MakeCellOfTypeCreatesCell) {
    ArrayArchetype<AnyArchetype> array;
    array.makeCellOfType<ArrayArchetype<>>();
    BOOST_REQUIRE_EQUAL(array.size(), 1);
    BOOST_CHECK_EQUAL(*array[0], ArrayArchetype<>{});
}

BOOST_AUTO_TEST_CASE(Test_ArrayArchetype_ParameterizedMakeCellOfTypeCreatesCellCorrectly) {
    ArrayArchetype<AnyArchetype> array;
    array.makeCellOfType<ArrayArchetype<>>(std::vector{mkPtr<ScalarArchetype>(4)});
    BOOST_REQUIRE_EQUAL(array.size(), 1);
    BOOST_CHECK_EQUAL(*array[0], ArrayArchetype<>{mkPtr<ScalarArchetype>(4)});
}

BOOST_AUTO_TEST_CASE(Test_ArrayArchetype_AsStringWorks) {
    ArrayArchetype<> array1{mkPtr<TrueScalarType>(1.1), mkPtr<TrueScalarType>(2)};
    ArrayArchetype<AnyArchetype> array2{
            mkPtr<CharacterScalarType>((int) 'a'),
            mkPtr<ArrayArchetype<>>(std::vector{
                    mkPtr<ScalarArchetype>(4)
            })
    };
    ArrayArchetype<AnyArchetype> array3;
    BOOST_CHECK(array1.asString() == CQT_STRING("$(1.1, 2)"));
    BOOST_CHECK(array2.asString() == CQT_STRING("$('a', $(4))"));
    BOOST_CHECK(array3.asString() == CQT_STRING("$()"));
}

BOOST_AUTO_TEST_CASE(Test_ArrayArchetype_GetAsWorks) {
    ArrayArchetype<> array{mkPtr<TrueScalarType>((int) 'b' + 2), mkPtr<TrueScalarType>((int) 'a')};
    BOOST_CHECK_EQUAL(*array.getAs<CharacterScalarType>(0), CharacterScalarType((int) 'd'));
    BOOST_CHECK_EQUAL(*array.getAs<CharacterScalarType>(1), CharacterScalarType((int) 'a'));

}

#pragma clang diagnostic pop

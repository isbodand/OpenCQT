//
// Created by bodand on 2019-05-29.
//

#pragma once

#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemberFunctionCanBeStaticInspection"
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <boost/test/included/unit_test.hpp>

#include <vector>

#include "../types/archetypes/ArchetypeUtilities.hpp"
#include "../types/archetypes/HashArchetype.hpp"
#include "../types/archetypes/ScalarArchetype.hpp"
#include "../types/archetypes/ArrayArchetype.hpp"
#include "../types/archetypes/ReferenceArchetype.hpp"

using namespace LibCqt;

BOOST_AUTO_TEST_CASE(Test_ArchetypeUtils_Casts_ArrayToScalar) {
    BOOST_CHECK_EQUAL(ScalarArchetype(),
                      *archetype_cast<ScalarArchetype>(mkPtr<ArrayArchetype<>>()));
    BOOST_CHECK_EQUAL(ScalarArchetype(1),
                      *archetype_cast<ScalarArchetype>(mkPtr<ArrayArchetype<>>(
                              std::vector{
                                      mkPtr<ScalarArchetype>()
                              })));
}

BOOST_AUTO_TEST_CASE(Test_ArchetypeUtils_ArrayToHash) {
    HashArchetype<Map> hash = HashArchetype<Map>();
    BOOST_CHECK_EQUAL(hash,
                      *archetype_cast<HashArchetype<Map>>(mkPtr<ArrayArchetype<>>()));
    hash.makeCellOfType<ScalarArchetype>("0"_cqt);
    BOOST_CHECK_EQUAL(hash,
                      *archetype_cast<HashArchetype<Map>>(mkPtr<ArrayArchetype<>>(
                              std::vector{
                                      mkPtr<ScalarArchetype>()
                              })));
}

//todo
//BOOST_AUTO_TEST_CASE(Test_ArchetypeUtils_ArrayToReference) {
//}

BOOST_AUTO_TEST_CASE(Test_ArchetypeUtils_ScalarToArray) {
    BOOST_CHECK_EQUAL(ArrayArchetype<>{mkPtr<ScalarArchetype>()},
                      *archetype_cast<ArrayArchetype<>>(mkPtr<ScalarArchetype>()));
    BOOST_CHECK_EQUAL(ArrayArchetype<>{mkPtr<ScalarArchetype>(4)},
                      *archetype_cast<ArrayArchetype<>>(mkPtr<ScalarArchetype>(4)));
}

BOOST_AUTO_TEST_CASE(Test_ArchetypeUtils_ScalarToHash) {
    HashArchetype<Map> hash = HashArchetype<Map>();
    hash.makeCellOfType<ScalarArchetype>("0"_cqt);
    BOOST_CHECK_EQUAL(hash,
                      *archetype_cast<HashArchetype<Map>>(mkPtr<ScalarArchetype>()));
    HashArchetype<Map> hash_ = HashArchetype<Map>();
    hash_.makeCellOfType<ScalarArchetype>("0"_cqt, 4);
    BOOST_CHECK_EQUAL(hash_,
                      *archetype_cast<HashArchetype<Map>>(
                              mkPtr<ScalarArchetype>(4)
                      ));
}


#pragma clang diagnostic pop

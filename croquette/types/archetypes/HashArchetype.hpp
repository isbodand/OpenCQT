//
// Created by bodand on 2019-03-25.
//

#pragma once

#include <type_traits>
#include <map>
#include <memory>
#include <unordered_map>

#include "AnyArchetype.hpp"
#include "ArchetypeUtilities.hpp"

namespace LibCqt {
    template<class K, class V>
    using Map = std::map<K, V>;

    template<class K, class V>
    using Hashmap = std::unordered_map<K, V>;

    template<template<class, class> class T>
    class HashArchetype : public AnyArchetype {
    protected:
        T<String, AnyArchetype_P> map;
    public:
        HashArchetype();
    };
}

template<template<class, class> class T>
LibCqt::HashArchetype<T>::HashArchetype() : AnyArchetype(LibCqt::Hash) {}
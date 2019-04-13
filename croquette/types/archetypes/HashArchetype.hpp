//
// Created by bodand on 2019-03-25.
//

#pragma once

#include <type_traits>
#include <map>
#include <memory>
#include <unordered_map>
#include <algorithm>

#include "AnyArchetype.hpp"

namespace LibCqt {
    template<class K, class V>
    using Map = std::map<K, V>;

    template<class K, class V>
    using Hashmap = std::unordered_map<K, V>;

    template<template<class, class> class ContImpl>
    class HashArchetype : public AnyArchetype {
    protected:
        ContImpl<String, AnyArchetype_P> map;
        virtual String printStart();
        virtual String printEnd();

    public:
        String asString() override;

        HashArchetype();

        template<template<class, class> class OthContImpl>
        explicit HashArchetype(CRf<HashArchetype<OthContImpl>> copy);

        virtual ~HashArchetype();

        template<class C,
                 typename = typename std::enable_if_t<std::is_default_constructible_v<C>>>
        std::size_t makeCellOfType(CRf<String> name);
        template<class C, class... Args>
        std::size_t makeCellOfType(CRf<String> name, Args... args);
        template<class R = AnyArchetype>
        Ptr<R> getAs(CRf<String> name);

        CRf<ContImpl<String, AnyArchetype_P>> getMap() const;
    };
    /// Pointer types
    template<template<class, class> class T = Hashmap>
    using HashArchetype_P = Ptr<HashArchetype<T>>;
    template<template<class, class> class T = Hashmap>
    using HashArchetype_R = Raw<HashArchetype<T>>;
}

template<template<class, class> class T>
LibCqt::HashArchetype<T>::HashArchetype() : AnyArchetype(LibCqt::Hash) {}
//
//template<template<class, class> class ContImpl>
//template<template<class, class> class OthContImpl>
//LibCqt::HashArchetype<ContImpl>::HashArchetype(CRf<HashArchetype<OthContImpl>> copy)


template<template<class, class> class ContImpl>
LibCqt::String LibCqt::HashArchetype<ContImpl>::printStart() {
    return CQT_STRING("(");
}

template<template<class, class> class ContImpl>
LibCqt::String LibCqt::HashArchetype<ContImpl>::printEnd() {
    return CQT_STRING(")");
}

template<template<class, class> class ContImpl>
LibCqt::String LibCqt::HashArchetype<ContImpl>::asString() {
    StringStream stream;
    stream << printStart();
    for (auto&& i = this->map.begin(); i != map.end(); ++i != map.end() && stream << CQT_STRING(", ")) {
        stream << CQT_CHAR('"') << i->first << CQT_STRING("\" -> ") << i->second->asString();
    }
    stream << printEnd();
    return std::move(stream.str());
}

template<template<class, class> class ContImpl>
LibCqt::HashArchetype<ContImpl>::~HashArchetype() = default;

template<template<class, class> class ContImpl>
template<class C, typename>
std::size_t LibCqt::HashArchetype<ContImpl>::makeCellOfType(CRf<LibCqt::String> name) {
    map[name] = mkPtr<C>();
    return map.size();
}

template<template<class, class> class ContImpl>
template<class C, class... Args>
std::size_t LibCqt::HashArchetype<ContImpl>::makeCellOfType(CRf<LibCqt::String> name, Args... args) {
    map[name] = mkPtr<C>(args...);
    return map.size();
}

template<template<class, class> class ContImpl>
template<class R>
LibCqt::Ptr<R> LibCqt::HashArchetype<ContImpl>::getAs(CRf<LibCqt::String> name) {
    return std::dynamic_pointer_cast<R>(map[name]);
}

template<template<class, class> class ContImpl>
LibCqt::CRf<ContImpl<LibCqt::String, LibCqt::AnyArchetype_P>> LibCqt::HashArchetype<ContImpl>::getMap() const {
    return map;
}

template<template<class, class> class ContImpl>
template<template<class, class> class OthContImpl>
LibCqt::HashArchetype<ContImpl>::HashArchetype(const LibCqt::HashArchetype<OthContImpl>& copy)
        : AnyArchetype(LibCqt::Hash) {
    for (auto&& i = copy.map.begin(); i != copy.map.end(); ++i) {
        map[i->first] = i->second;
    }
}

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
  public: // Types
      using T = ContImpl<String, AnyArchetype_P>;
      using U = void;
      using Archetype = HashArchetype<ContImpl>;
      using _Archetype = HashArchetype;

  protected: // Fields
      ContImpl<String, AnyArchetype_P> map;

  protected: // Virtual protected methods
      virtual String printStart() const;
      virtual String printEnd() const;

  public: // Overridden methods
      String asString() const override;

  public: // Constructors & destructor
      HashArchetype();
      HashArchetype(HashArchetype& cp) = default;
      HashArchetype(HashArchetype&& mv) noexcept = default;
      template<template<class, class> class S>
      explicit HashArchetype(const Ptr <HashArchetype<S>>& ptrcp);

      virtual ~HashArchetype();

  public: // Operators
      HashArchetype& operator=(HashArchetype& cp) = default;
      HashArchetype& operator=(HashArchetype&& mv) noexcept = default;

      bool operator==(const HashArchetype& rhs) const;
      bool operator!=(const HashArchetype& rhs) const;
  public: // Miscellaneous methods
      template<class C>
      ENABLE_IF std::is_default_constructible_v<C>
                && (std::is_same_v<C, AnyArchetype>
                    || std::is_base_of_v<AnyArchetype, C>)THEN
      (std::size_t) makeCellOfType(const String& name);
      template<class C,
              class... Args>
      ENABLE_IF std::is_constructible_v<C, Args...>
                && (std::is_same_v<C, AnyArchetype>
                    || std::is_base_of_v<AnyArchetype, C>)THEN
      (std::size_t) makeCellOfType(const String& name, Args... args);
      template<class R = AnyArchetype>
      Ptr <R> getAs(const String& name);

      std::size_t size() const;

      const ContImpl<String, AnyArchetype_P>& getMap() const;
  };
  /// Pointer types
  template<template<class, class> class T = Hashmap>
  using HashArchetype_P = Ptr<HashArchetype<T>>;
  template<template<class, class> class T = Hashmap>
  using HashArchetype_R = HashArchetype<T>*;
}

template<template<class, class> class T>
LibCqt::HashArchetype<T>::HashArchetype()
        : AnyArchetype(LibCqt::archHash) {}
//
//template<template<class, class> class ContImpl>
//template<template<class, class> class OthContImpl>
//LibCqt::HashArchetype<ContImpl>::HashArchetype(const HashArchetype<OthContImpl>& copy)


template<template<class, class> class ContImpl>
LibCqt::String LibCqt::HashArchetype<ContImpl>::printStart() const {
    return CQT_STRING("(");
}

template<template<class, class> class ContImpl>
LibCqt::String LibCqt::HashArchetype<ContImpl>::printEnd() const {
    return CQT_STRING(")");
}

template<template<class, class> class ContImpl>
LibCqt::String LibCqt::HashArchetype<ContImpl>::asString() const {
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
template<class C>
ENABLE_IF std::is_default_constructible_v<C>
          && (std::is_same_v<C, LibCqt::AnyArchetype>
              || std::is_base_of_v<LibCqt::AnyArchetype, C>)THEN
(std::size_t) LibCqt::HashArchetype<ContImpl>::makeCellOfType(const LibCqt::String& name) {
    map[name] = mkPtr<C>();
    return map.size();
}

template<template<class, class> class ContImpl>
template<class C, class... Args>
ENABLE_IF std::is_constructible_v<C, Args...>
          && (std::is_same_v<C, LibCqt::AnyArchetype>
              || std::is_base_of_v<LibCqt::AnyArchetype, C>)THEN
(std::size_t) LibCqt::HashArchetype<ContImpl>::makeCellOfType(const LibCqt::String& name, Args... args) {
    map[name] = mkPtr<C>(args...);
    return map.size();
}

template<template<class, class> class ContImpl>
template<class R>
LibCqt::Ptr<R> LibCqt::HashArchetype<ContImpl>::getAs(const LibCqt::String& name) {
    // note: static_pointer_cast doesn't work
    return mkPtr<R>(*static_cast<R*>(map[name].get()));
}

template<template<class, class> class ContImpl>
const ContImpl<LibCqt::String, LibCqt::AnyArchetype_P>&
LibCqt::HashArchetype<ContImpl>::getMap() const {
    return map;
}

template<template<class, class> class ContImpl>
std::size_t LibCqt::HashArchetype<ContImpl>::size() const {
    return map.size();
}

template<template<class, class> class ContImpl>
template<template<class, class> class S>
LibCqt::HashArchetype<ContImpl>::HashArchetype(const Ptr <LibCqt::HashArchetype<S>>& ptrcp)
        : map(ptrcp->getMap()) {
}

template<template<class, class> class ContImpl>
bool LibCqt::HashArchetype<ContImpl>::operator==(const HashArchetype& rhs) const {
    if (getHashType() != rhs.getHashType())
        return false;

    if (rhs.map.size() != map.size())
        return false;

    bool eq = true;
    auto i = map.begin();
    auto j = rhs.map.begin();
    while (eq && i != map.end()) {
        eq = i->first == j->first
             && *(i++)->second == *(j++)->second;
    }
    eq = eq && i == map.end();

    return static_cast<const AnyArchetype&>(*this) == static_cast<const AnyArchetype&>(rhs) &&
           eq;
}

template<template<class, class> class ContImpl>
bool LibCqt::HashArchetype<ContImpl>::operator!=(const HashArchetype& rhs) const {
    return !(rhs == *this);
}

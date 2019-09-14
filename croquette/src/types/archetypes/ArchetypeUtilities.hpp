//
// Created by bodand on 2019-03-25.
//

#pragma once

#include <memory>
#include <type_traits>

#include "../ImplementationTypes.hpp"
#include "AnyArchetype.hpp"
#include "ArrayArchetype.hpp"
#include "ScalarArchetype.hpp"
#include "HashArchetype.hpp"
#include "../user_types/FlatArrayType.hpp"
#include "../user_types/ComplexArrayType.hpp"

namespace LibCqt {
  template<class R, class T, template<class> class ShdPtr>
  Ptr<R> archetype_cast(const ShdPtr<T>& shared);

  namespace _Impl {
    template<class T, class U>
    constexpr bool absorbs();

    //&!off
        template<class RWrapper, class InWrapper,
                 typename RType = typename RWrapper::actual, typename RArche = typename RWrapper::type,
                 typename RT = typename RWrapper::t, typename RU = typename RWrapper::u,
                 typename InType = typename InWrapper::actual,
                 typename InArche = typename InWrapper::type,
                 typename InT = typename InWrapper::t, typename InU = typename InWrapper::u>
        constexpr Ptr<RType> archetype_cast(InType* in);
        //&!on

    //&!off
        /// Array -> Scalar
        template<class RType, class RArche, class RT, class RU,
                 class InType, class InArche, class InT, class InU>
        static ENABLE_IF std::is_same_v<RT, void> && std::is_same_v<RU, void>
                         && std::is_base_of_v<ScalarArchetype, RType>
                         && !(std::is_same_v<InT, void> || std::is_same_v<InU, void>)
                         && std::is_base_of_v<ArrayArchetype<InT, InU>, InType> THEN //&!on
        (Ptr<RType>) _archetype_cast(InType* array) {
        return mkPtr<RType>(array->size());
    }

    //&!off
        /// Array -> Hash
        template<class RType, class RArche, class RT, class RU,
                 class InType, class InArche, class InT, class InU>
        static ENABLE_IF !std::is_same_v<RT, void> && std::is_same_v<RU, void>
                         && (std::is_base_of_v<HashArchetype<Map>, RType>
                             || std::is_base_of_v<HashArchetype<Hashmap>, RType>)
                         && !(std::is_same_v<InT, void> || std::is_same_v<InU, void>)
                         && std::is_base_of_v<ArrayArchetype<InT, InU>, InType> THEN //&!on
        (Ptr<RType>) _archetype_cast(InType* array) {
        auto ptr = mkPtr<RType>();
        for (int i = 0; i < array->getCells().size(); ++i) {
            ptr->template makeCellOfType<InU>(CQT_TO_STRING(i), array->getCells()[i]);
        }
        return ptr;
    }

    //&!off
        /// Scalar -> Array
        template<class RType, class RArche, class RT, class RU,
                 class InType, class InArche, class InT, class InU>
        static ENABLE_IF !(std::is_same_v<RT, void> || std::is_same_v<RU, void>)
                         && std::is_base_of_v<ArrayArchetype<RT, RU>, RType>
                         && std::is_same_v<InT, void> && std::is_same_v<InU, void>
                         && std::is_base_of_v<ScalarArchetype, InType> THEN //&!on
        (Ptr<RType>) _archetype_cast(InType* scalar) {
        auto ptr = mkPtr<RType>();
        ptr->template makeCellOfType<InType>(*scalar);
        return ptr;
    }

    //&!off
        /// Scalar -> Hash
        template<class RType, class RArche, class RT, class RU,
                 class InType, class InArche, class InT, class InU>
        static ENABLE_IF !std::is_same_v<RT, void> && std::is_same_v<RU, void>
                         && (std::is_base_of_v<HashArchetype<Map>, RType>
                             || std::is_base_of_v<HashArchetype<Hashmap>, RType>)
                         && std::is_same_v<InT, void> && std::is_same_v<InU, void>
                         && std::is_base_of_v<ScalarArchetype, InType> THEN //&!on
        (Ptr<RType>) _archetype_cast(InType* scalar) {
        auto ptr = mkPtr<RType>();
        ptr->template makeCellOfType<InType>("0"_cqt, *scalar);
        return ptr;
    }

    //&!off
        /// Hash -> Scalar
        template<class RType, class RArche, class RT, class RU,
                 class InType, class InArche, class InT, class InU>
        static ENABLE_IF std::is_same_v<RT, void> && std::is_same_v<RU, void>
                         && std::is_base_of_v<ScalarArchetype, RType>
                         && !std::is_same_v<InT, void> && std::is_same_v<InU, void>
                         && (std::is_base_of_v<HashArchetype<Map>, InType>
                             || std::is_base_of_v<HashArchetype<Hashmap>, InType>) THEN //&!on
        (Ptr<RType>) _archetype_cast(InType* hash) {
        return mkPtr<RType>(hash->size());
    }

    //&!off
        /// Hash -> Array
        template<class RType, class RArche, class RT, class RU,
                class InType, class InArche, class InT, class InU>
        static ENABLE_IF !(std::is_same_v<RT, void> || std::is_same_v<RU, void>)
                         && std::is_base_of_v<ArrayArchetype<RT, RU>, RType>
                         && !std::is_same_v<InT, void> && std::is_same_v<InU, void>
                         && (std::is_base_of_v<HashArchetype<Map>, InType>
                            || std::is_base_of_v<HashArchetype<Hashmap>, InType>) THEN //&!on
        (Ptr<RType>) _archetype_cast(InType* hash) {
        auto ptr = mkPtr<RType>();
        for (auto&&[_, val] : hash->getMap()) {
            switch (val->getCurrentType()) {
                case archScalar: // Every array can store any scalar
                    switch (val->getScalarType()) {
                        case scalarAnyScalar:ptr->template makeCellOfType<ScalarArchetype>(val);
                            break;
                        case scalarCharacterScalar:ptr->template makeCellOfType<CharacterScalarType>(val);
                            break;
                        case scalarTrueScalar:ptr->template makeCellOfType<TrueScalarType>(val);
                            break;
                    }
                    break;
                case archArray:
                    switch (val->getArrayType()) {
                        case arrayAnyArray:
                        case arrayFlatArray:
                            if constexpr (absorbs<RT, ArrayArchetype>()) {
                                ptr->template makeCellOfType<FlatArrayType>(val);
                            } else {
                                ptr->template makeCellOfType<TrueScalarType>(
                                        ::LibCqt::archetype_cast<TrueScalarType>(val));
                            }
                            break;
                        case arrayComplexArray:
                            if constexpr (absorbs<RT, ArrayArchetype>()) {
                                ptr->template makeCellOfType<ComplexArrayType>(val);
                            } else {
                                ptr->template makeCellOfType<TrueScalarType>(
                                        ::LibCqt::archetype_cast<TrueScalarType>(val));
                            }
                            break;
                    }
                    break;
                case archHash:
                    switch (val->getHashType()) {

                    }
                    break;
                case archReference: //todo
//                        switch (val->getScalarType()) {
//
//                        }
                    break;
            }
        }
        return ptr;
    }
  }
}

template<class R, class T, template<class> class ShdPtr>
LibCqt::Ptr<R> LibCqt::archetype_cast(const ShdPtr<T>& shared) {
    auto&& ptr = shared.get();
    return _Impl::archetype_cast<TypeWrapper<R>, TypeWrapper<T>>(ptr);
}

template<class RWrapper, class InWrapper,
        typename RType, typename RArche, typename RT, typename RU,
        typename InType, typename InArche, typename InT, typename InU>
constexpr LibCqt::Ptr<RType> LibCqt::_Impl::archetype_cast(InType* in) {
    return _archetype_cast<RType, RArche, RT, RU, InType, InArche, InT, InU>(in);
}

template<class T, class U>
constexpr bool LibCqt::_Impl::absorbs() {
    return std::is_assignable_v<T&, U>();
}

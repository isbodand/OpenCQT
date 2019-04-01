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

namespace LibCqt {
    template<class R, class T, template<class> class ShdPtr>
    Ptr<R> archetype_cast(const ShdPtr<T>& shared);

    namespace _Impl {
        template<class RWrapper, class InWrapper,
                 typename RType = typename RWrapper::actual, typename RArche = typename RWrapper::type,
                 typename RT = typename RWrapper::t, typename RU = typename RWrapper::u,
                 typename InType = typename InWrapper::actual,
                 typename InArche = typename InWrapper::type,
                 typename InT = typename InWrapper::t, typename InU = typename InWrapper::u>
        constexpr Ptr<RType> archetype_cast(const Raw<InType>& in);

        /// Array -> Scalar
        template<class RType, class RArche, class RT, class RU,
                 class InType, class InArche, class InT, class InU>
        std::enable_if_t<std::is_same_v<RT, void> && std::is_same_v<RU, void> &&
                         std::is_base_of_v<ScalarArchetype, RArche> &&
                         !(std::is_same_v<InT, void> || std::is_same_v<InU, void>) &&
                         std::is_base_of_v<ArrayArchetype<InT, InU>, InArche>,
                /**/ Ptr<RType>>
        _archetype_cast(const Raw<InType>& array) {
            return mkPtr<RType>(array->size());
        }

        //        /// Array -> Hash
        //        template<template<template<class, class> class> class R,
        //                template<class, class> class hT,
        //                class aT, class aU = aT,
        //                typename = typename std::enable_if_t<std::is_base_of_v<HashArchetype<hT>, R<hT>>>>
        //        Ptr<R<hT>> _archetype_cast(const ArrayArchetype_R<aT, aU>& array);
        /// Scalar -> Array
        template<class RType, class RArche, class RT, class RU,
                 class InType, class InArche, class InT, class InU>
        std::enable_if_t<!(std::is_same_v<RT, void> || std::is_same_v<RU, void>) &&
                         std::is_base_of_v<ArrayArchetype<RT, RU>, RArche> &&
                         std::is_same_v<InT, void> && std::is_same_v<InU, void> &&
                         std::is_base_of_v<ScalarArchetype, InArche>,
                /**/ Ptr<RType>>
        _archetype_cast(const Raw<InType>& array) {
            auto ptr = mkPtr<RType>();
            ptr->template makeCellOfType<InType>(*array);
            return ptr;
        }
        //        /// Scalar -> Hash
        //        template<template<template<class, class> class> class R, template<class, class> class T,
        //                 typename = typename std::enable_if_t<std::is_base_of_v<HashArchetype<T>, R<T>>>>
        //        Ptr<R<T>> _archetype_cast(const ScalarArchetype_R& scalar);
        //@formatter:on
    }
}

template<class R, class T, template<class> class ShdPtr>
LibCqt::Ptr<R> LibCqt::archetype_cast(const ShdPtr<T>& shared) {
    auto&& ptr = shared.get();
    return _Impl::archetype_cast<TypeWrapper<R>, TypeWrapper<T>>(ptr);
}

///// Array -> Hash
//template<template<template<class, class> class> class R,
//        template<class, class> class hT, class aT, class aU, typename>
//LibCqt::Ptr<R<hT>> LibCqt::_Impl::_archetype_cast(const LibCqt::ArrayArchetype_R<aT, aU>& array) {
//    return mkPtr<R<hT>>(array->getCells());
//}
//
///// Array -> Scalar
//template<class R, class T, class U, typename>
//LibCqt::Ptr<R> LibCqt::_Impl::_archetype_cast(const LibCqt::ArrayArchetype_R<T, U>& array) {
//    return mkPtr<R>(array->size());
//}

template<class RWrapper, class InWrapper,
         typename RType, typename RArche, typename RT, typename RU,
         typename InType, typename InArche, typename InT, typename InU>
constexpr LibCqt::Ptr<RType> LibCqt::_Impl::archetype_cast(LibCqt::Raw<InType> const& in) {
    return _archetype_cast<RType, RArche, RT, RU, InType, InArche, InT, InU>(in);
}

///// Scalar -> Array
//template<template<class, class> class R, class T, class U, typename>
//LibCqt::Ptr<R<T, U>> LibCqt::_Impl::_archetype_cast(const LibCqt::ScalarArchetype_R& scalar) {
//    return mkPtr<R<T, U>>(scalar->getValue());
//}
//
//
/////// Scalar -> Hash
//template<template<template<class, class> class> class R,
//        template<class, class> class T, typename>
//LibCqt::Ptr<R<T>> LibCqt::_Impl::_archetype_cast(const LibCqt::ScalarArchetype_R& scalar) {
//    return mkPtr<R<T>>(scalar->getValue());
//}

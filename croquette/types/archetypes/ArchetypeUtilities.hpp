//
// Created by bodand on 2019-03-25.
//

#pragma once

#include <memory>
#include "../ImplementationTypes.hpp"
#include "AnyArchetype.hpp"
#include "ArrayArchetype.hpp"
#include "ScalarArchetype.hpp"

namespace LibCqt {
    /// Pointer types. Use unless death is imminent
    using AnyArchetype_P = Ptr<AnyArchetype>;
    template<class T = ScalarArchetype, class U = T>
    using ArrayArchetype_P = Ptr <ArrayArchetype<T, U>>;
    using ScalarArchetype_P = Ptr<ScalarArchetype>;

    /// C-Style Raw pointers. Use with high care, and when made sure _P can't be used
    using AnyArchetype_R = Raw<AnyArchetype>;
    template<class T = ScalarArchetype, class U = T>
    using ArrayArchetype_R = Raw <ArrayArchetype<T, U>>;
    using ScalarArchetype_R = Raw<ScalarArchetype>;

    template<class R, class T, template<class> class ShdPtr>
    Ptr <R> archetype_cast(const ShdPtr<T>& shared);

    namespace _Impl {
        template<class ArrayT = ScalarArchetype, class DefConstructedT = ArrayT>
        ScalarArchetype_R archetype_cast(ArrayArchetype_R<ArrayT, DefConstructedT> val);

        template<class ArrayT = ScalarArchetype, class DefConstructedT = ArrayT>
        ArrayArchetype_R<ArrayT, DefConstructedT> archetype_cast(ScalarArchetype_R val);
    }
}

template<class R, class T, template<class> class ShdPtr>
LibCqt::Ptr<R> LibCqt::archetype_cast(const ShdPtr<T>& shared) {
    auto raw = reinterpret_cast<Raw<R>>(_Impl::archetype_cast(shared.get()));
    return Ptr<R>(raw);
}

template<class T, class U>
LibCqt::ScalarArchetype_R LibCqt::_Impl::archetype_cast(LibCqt::ArrayArchetype_R<T, U> val) {
    return mkRaw<LibCqt::ScalarArchetype>(val->size());
}

template<class T, class U>
LibCqt::ArrayArchetype_R<T, U> LibCqt::_Impl::archetype_cast(LibCqt::ScalarArchetype_R val) {
    auto raw = mkRaw<ArrayArchetype<T, U>>();
    raw->makeCell(val);
    return raw;
}

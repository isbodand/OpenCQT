//
// Created by bodand on 2019-03-28.
//

#pragma once

#include <memory>

#define ENABLE_IF typename std::enable_if<
#define THEN(T) ,T>::type

namespace LibCqt {
    /**
     * Shared pointer typedef
     * Used to shorten typing
     */
    template<class... Args>
    using Ptr = std::shared_ptr<Args...>;

    /**
     * Raw pointer typedef
     * Used to maintain uniformity
     */
    template<class T>
    using Raw = T*;

    /**
     * Unique pointer as a dynamically allocated
     * *Ins*tance
     * Used to maintain unifomity and shorten typing
     */
    template<class T>
    using Ins = std::unique_ptr<T>;

    /**
     * Reference for uniformity
     */
    template<class T>
    using Ref = T&;

    /**
     * Const Reference for uniformity
     */
    template<class T>
    using CRf = const T&;

    /**
     * RValue Reference for uniformity
     */
    template<class T>
    using RRf = T&&;

    /// Manufacturing functions

    /*Ptr<ConT>*/
    template<class T, class... Args>
    constexpr Ptr<T> mkPtr(Args... args) {
        return std::make_shared<T>(args...);
    }

    template<class T>
    constexpr Ptr<T> mkPtr(Raw<T> raw) {
        return Ptr<T>(raw);
    }

    /*Raw<ConT>*/
    template<class T, class... Args>
    constexpr Raw<T> mkRaw(Args... args) {
        return new T(args...);
    }

    template<class T>
    constexpr void rmRaw(Raw<T> raw) {
        delete raw;
    }

    /*Ins<ConT>*/
    template<class T, class... Args>
    constexpr Ins<T> mkIns(Args... args) {
        return std::make_unique<T>(args...);
    }

    ////// Type wrapper
    template<class Type>
    struct TypeWrapper {
        using type = typename Type::Archetype;
        using actual = Type;
        using t = typename Type::T;
        using u = typename Type::U;
    };
}

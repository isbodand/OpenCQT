//
// Created by bodand on 2019-03-28.
//

#pragma once

#include <memory>

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

    /// Manufacturing functions

    /*Ptr<T>*/
    template<class T, class... Args>
    constexpr Ptr<T> mkPtr(Args... args) {
        return std::make_shared<T>(args...);
    }

    template<class T>
    constexpr Ptr<T> mkPtr(Raw<T> raw) {
        return Ptr<T>(raw);
    }

    /*Raw<T>*/
    template<class T, class... Args>
    constexpr Raw<T> mkRaw(Args... args) {
        return new T(args...);
    }

    /*Ins<T>*/
    template<class T, class... Args>
    constexpr Ins<T> mkIns(Args... args) {
        return std::make_unique<T>(args...);
    }
}
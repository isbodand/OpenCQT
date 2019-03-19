#pragma once

#include "ArrayArchetype.hpp"
#include "ScalarArchetype.hpp"

#include <type_traits>

namespace LibCroquette {
    template<class To, class From>
    std::enable_if<
        std::is_base_of_v<ArcheType, From> && 
        std::is_base_of_v<ArcheType, To> && 
        std::is_same_v<From, To>, 
        To
    >::type
    /*To*/ castArchetype(From from) {
        return dynamic_cast<To>(from);
    }

    template<class To, class From>
    std::enable_if<
        std::is_same_v<ArrayArchetype, To> && std::is_same_v<ScalarArchetype, From>,
        To
    >::type
    /* To */ castArchetype(From from) {
        //todo
    }
}


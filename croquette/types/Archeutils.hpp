#pragma once

namespace LibCroquette {
   template<class To, class From>
    std::enable_if<std::is_same<
        std::declval<From>().castTo<To>(),
        To
    >, To>::type
    /*To*/ castArchetype(From from, To to) {
            //todo 
    }
}


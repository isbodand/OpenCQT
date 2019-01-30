#pragma once

#include <typeinfo>
#include <map>

namespace InfoParse {
    class TypeInferingParameterHandler {
        // ez felettébb biztonságos
        std::map<void*, void*> handlers;
    }
}


#pragma once

#include <typeinfo>
#include <typeindex>
#include <map>
#include "options/ParseOption.hpp"
#include "ParameterHandler.hpp"

namespace InfoParse {
    class TypeInferingParameterHandler {
        std::map<std::type_index, void*> handlers;

    public:
        template<class T>
        void addOption(const ParseOption <T>& opt);

        //todo this
        // MatchResult<???> parse(const std::string& args);
    };

    template<class T>
    void TypeInferingParameterHandler::addOption(const ParseOption <T>& opt) {
        if (handlers.find(typeid(T)) == handlers.end()) {
            handlers[typeid(T)] = (void*) new ParameterHandler<T>();
        }
        ((ParameterHandler<T>*) handlers[typeid(T)])->addParameter(opt);
    }

    using OptionParser = TypeInferingParameterHandler;
}


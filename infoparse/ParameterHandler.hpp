//
// Created by bodand on 2019-01-20.
//

#pragma once

#include <list>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <sstream>
#include "options/ParseOption.hpp"

namespace InfoParse {

    template<class T>
    class ParameterHandler {
        typedef std::pair<std::vector<std::string>*, std::map<std::string, T>> ParseReturnType;

        std::list<ParseOption<T>> parameters;

    public:
        ParameterHandler() = default;

        virtual ~ParameterHandler() = default;

        void addParameter(ParseOption<T> parseOption);

        // I'm not going to deal with extracting this
        // with the template and dependent return-type
        ParseReturnType parse(const std::string& args) {
            ParseReturnType retVal;
            std::string argsToMatch = args;
            for (ParseOption<T>& parameter : parameters) {
                auto matchRes = parameter.match(argsToMatch);
                if (matchRes.isSuccessful()) {
                    argsToMatch = matchRes.getResultString();
                    if (parameter.isTakesValue()) {
                        retVal.second[parameter.getOptionName()] = parameter.getValue();
                    } else {
                        retVal.second[parameter.getOptionName()] = T();
                    }
                }
            }
            std::istringstream remnants(argsToMatch);
            retVal.first = new std::vector<std::string>{std::istream_iterator<std::string>{remnants},
                                                        std::istream_iterator<std::string>{}};
            return retVal;
        }
    };

    template<class T>
    void ParameterHandler<T>::addParameter(ParseOption<T> parseOption) {
        parameters.push_back(parseOption);
    }
}


#pragma once

#include <cstdio>

namespace InfoParse {
    template <class T>
    class Option {
        std::string longName;
        char shortName;
        T* exporter;

    public:
        std::string match(const std::string& args);
    }

    template<class T>
    std::string Option<T>::match(const std::string& args) {
        args.find("--" + longName + " ");
    }
}


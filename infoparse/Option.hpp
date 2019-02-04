#pragma once

#include <utility>
#include <string>

#include "utils.hpp"

namespace InfoParse {
    template<class T>
    class Option {
        std::string longName;
        char shortName;
        T* exporter;

    public:
        Option(std::string longName, char shortName, T* exporter);
        Option(const std::string& longName, T* exporter);

        std::string match(const std::string& args);
    };

    template<class T>
    std::string Option<T>::match(const std::string& args) {
        std::string parsable(args);
        std::size_t startMatch;
        const auto longSequence = " --" + longName + " ";
        const auto shortSequence = std::string(" -" + shortName + " ");

        unless ((startMatch = parsable.find(longSequence)) == -1) {
            std::size_t matchLength = longSequence.length();
            // todo extend match to contain param
            std::string match = parsable.substr(startMatch, matchLength);
            parsable.erase(startMatch, matchLength);

            char* retRaw;
            std::sscanf(match.c_str(), (" --" + longName + " %ms ").c_str(), retRaw);
            std::string ret(retRaw);
            free((void*) retRaw);
        } else unless ((startMatch = parsable.find(shortSequence)) == -1) {
            std::size_t matchLength = shortSequence.length();
        }
    }

    template<class T>
    Option<T>::Option(std::string longName, char shortName, T* exporter):
            longName(std::move(longName)),
            shortName(shortName),
            exporter(exporter) {}

    template<class T>
    Option<T>::Option(const std::string& longName, T* exporter):
            longName(longName),
            shortName(longName[0]),
            exporter(exporter) {}
}


//
// Created by bodand on 2019-02-06.
//
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
#pragma once

#include <typeinfo>
#include <typeindex>
#include <string>
#include <map>
#include <memory>

#include "utils.hpp"
#include "__OptionHandler.hpp"

namespace InfoParse {
    class OptionsParser {
        std::map<std::type_index, std::pair<void*,
                                            std::function<std::string(void*, const std::string&)>>>
                optionHandlers;

    public:
        OptionsParser();
        virtual ~OptionsParser();

        template<class T>
        ENABLE_IF true THEN
        (void) addOption(const std::string& longName, char shortName, T* exporter);
        template<class T>
        ENABLE_IF true THEN
        (void) addOption(const std::string& name, T* exporter);

        std::string parse(int argc, char** argv);
        std::string parse(const std::string& args);

    private:
        std::string explodeBundledFlags(const std::string& args);
        std::string equalizeWhitespace(const std::string& args);
    };

    template<class T>
    ENABLE_IF true THEN
    (void) OptionsParser::addOption(const std::string& longName, char shortName, T* exporter) {
        if (optionHandlers.find(typeid(T)) == optionHandlers.end()) {
            optionHandlers[typeid(T)].first = (void*) new __OptionHandler<T>();
            optionHandlers[typeid(T)].second = [](void* optionVoid, const std::string& args) {
                return ((__OptionHandler<T>*) optionVoid)->handle(args);
            };
        }
        __Option<T> option(longName, shortName, exporter);
        ((__OptionHandler<T>*) optionHandlers[typeid(T)].first)->addOption(option);
    }

    template<class T>
    ENABLE_IF true THEN
    (void) OptionsParser::addOption(const std::string& name, T* exporter) {
        if (optionHandlers.find(typeid(T)) == optionHandlers.end()) {
            optionHandlers[typeid(T)].first = (void*) new __OptionHandler<T>();
            optionHandlers[typeid(T)].second = [](void* optionVoid, const std::string& args) {
                return ((__OptionHandler<T>*) optionVoid)->handle(args);
            };
        }
        __Option<T> option(name, exporter);
        ((__OptionHandler<T>*) optionHandlers[typeid(T)].first)->addOption(option);
    }
}

#pragma clang diagnostic pop

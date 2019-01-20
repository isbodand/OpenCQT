#pragma once

#include <string>
#include <utility>
#include <optional>
#include <vector>
#include <cstring>

#include "../MatchResult.hpp"
#include "../unless.hpp"
#include "../ParseOptionEmptyException.hpp"

namespace InfoParse {

    static const char* const longOptNotation = "--";

    static const size_t longOptNotationLen = 2;

    static const char* const shortOptNotation = "-";

    static const size_t shortOptNotationLen = 1;

    template<class T>
    class ParseOption {
        std::string longOption;
        char shortOption;
        bool takesValue;
        bool acceptShortOption = true;

        bool found = false;
        long appeared = 0;
        T* value = nullptr;

    public:
        explicit ParseOption(const std::string& option);

        ParseOption(const std::string& option, bool takesValue);

        ParseOption(char shortOpt, std::string longOpt);

        ParseOption(char shortOpt, std::string longOpt, bool takesValue);

        /**
         * Returns current value of the ParseOption
         * throws ParseOptionEmptyException if empty
         */
        T getValue();

        const std::string& getLongOption() const;

        bool isAcceptShortOption() const;
        void setAcceptShortOption(bool acceptShortOption);

        /**
         * Parses the arguments string
         * @param args The string to parse
         * @return A MatchResult with the string
         *         which had the matched parameter removed
         *         and a bool whether there was a match
         */
        MatchResult match(const std::string& args);
        void noValueParse(std::string& args);
        void noValueLongParse(std::string& args);
        void noValueShortParse(std::string& args);
        void valueParse(std::string& args);
        void valueLongParse(std::string& args);
        void valueShortParse(const std::string& args);
    };

    template<class T>
    ParseOption<T>::ParseOption(char shortOpt, std::string longOpt, bool takesValue) :
            shortOption(shortOpt),
            longOption(std::move(longOpt)),
            takesValue(false) {
    }

    template<class T>
    T ParseOption<T>::getValue() {
        if (value == nullptr) {
            throw ParseOptionEmptyException(takesValue);
        }
        return *value;
    }

    template<class T>
    ParseOption<T>::ParseOption(const std::string& option) :
            longOption(option),
            shortOption(option[0]),
            takesValue(false) {
    }

    template<class T>
    ParseOption<T>::ParseOption(char shortOpt, std::string longOpt) :
            shortOption(shortOpt),
            longOption(std::move(longOpt)),
            takesValue(false) {
    }

    template<class T>
    ParseOption<T>::ParseOption(const std::string& option, bool takesValue) :
            shortOption(option[0]),
            longOption(option),
            takesValue(takesValue) {
    }

    template<class T>
    MatchResult ParseOption<T>::match(const std::string& args) {
        found = false;
        if (takesValue) {
            valueParse(args);
        } else {
            noValueParse(args);
        }
        return MatchResult(found, args);
    }

    template<class T>
    void ParseOption<T>::valueParse(std::string& args) {
        valueLongParse(args);
        if (!found && acceptShortOption) {
            valueShortParse(args);
        }
    }

    template<class T>
    void ParseOption<T>::valueShortParse(const std::string& args) {
        size_t shortPos = args.find(shortOptNotation + shortOption);
        unless (shortPos == -1) {
            found = true;
            ++appeared;
            const auto shortStart = 0 + shortPos;
            const auto shortEnd = shortStart + shortOptNotationLen + 1;
            const auto spaceStart = args.find_first_of(' ', shortEnd) + 1;
            const auto spaceEnd = args.find_first_not_of(' ', spaceStart);
            value = &static_cast<T>(args.substr(spaceStart, spaceEnd - spaceStart));
        }
    }

    template<class T>
    void ParseOption<T>::valueLongParse(std::string& args) {
        size_t longPos = args.find(longOptNotation + longOption);
        unless (longPos == -1) {
            found = true;
            ++appeared;
            const auto longStart = 0 + longPos;
            const auto longEnd = longStart + longOptNotationLen + longOption.length();
            const auto spaceStart = args.find_first_of(' ', longEnd) + 1;
            const auto spaceEnd = args.find_first_not_of(' ', spaceStart);
            value = &static_cast<T>(args.substr(spaceStart, spaceEnd - spaceStart));
        }
    }

    template<class T>
    void ParseOption<T>::noValueParse(std::string& args) {
        noValueLongParse(args);
        if (!found && acceptShortOption) {
            noValueShortParse(args);
        }
    }

    template<class T>
    void ParseOption<T>::noValueShortParse(std::string& args) {
        size_t shortPos = args.find(shortOptNotation + shortOption);
        unless (shortPos == -1) {
            found = true;
            ++appeared;
            auto shortStart = args.begin() + shortPos;
            auto shortEnd = shortStart + 2;
            args.erase(shortStart, shortEnd);
        }
    }

    template<class T>
    void ParseOption<T>::noValueLongParse(std::string& args) {
        size_t longPos = args.find(longOptNotation + longOption);
        unless (longPos == -1) {
            found = true;
            ++appeared;
            const auto longStart = args.begin() + longPos;
            const auto longEnd = longStart + (longOption.length() + 2);
            args.erase(longStart, longEnd);
        }
    }

    template<class T>
    const std::string& ParseOption<T>::getLongOption() const {
        return longOption;
    }

    template<class T>
    bool ParseOption<T>::isAcceptShortOption() const {
        return acceptShortOption;
    }

    template<class T>
    void ParseOption<T>::setAcceptShortOption(bool acceptShortOption) {
        ParseOption::acceptShortOption = acceptShortOption;
    }
}
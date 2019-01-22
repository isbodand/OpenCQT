#pragma once

#include <string>
#include <utility>
#include <optional>
#include <vector>
#include <cstring>
#include <functional>

#include "../MatchResult.hpp"
#include "../unless.hpp"
#include "../ParseOptionEmptyException.hpp"

namespace InfoParse {

    static const char* const longOptNotation = "--";

    static const size_t longOptNotationLen = 2;

    static const char shortOptNotation = '-';

    static const size_t shortOptNotationLen = 1;

    static const char separatorSpace = ' ';

    template<class T>
    class RawParseOption {
        std::string longOption;
        char shortOption;
        bool takesValue;
        bool acceptShortOption = true;

        bool found = false;
        long appeared = 0;
        void* value = nullptr;

    public:
        RawParseOption(const std::string& option);

        RawParseOption(const std::string& option, bool takesValue);

        RawParseOption(char shortOpt, std::string longOpt);

        RawParseOption(char shortOpt, std::string longOpt, bool takesValue);

        virtual ~RawParseOption();

        /**
         * Returns current value of the ParseOption
         * throws ParseOptionEmptyException if empty
         */
        T getValue();

        const std::string& getLongOption() const;

        bool doesAcceptShortOption() const;
        void setAcceptShortOption(bool acceptShortOption);

        bool isTakesValue() const;

        /**
         * Parses the arguments string
         * @param args The string to parse
         * @return A MatchResult with the string
         *         which had the matched parameter removed
         *         and a bool whether there was a match
         */
        MatchResult match(std::string& args);
        void noValueParse(std::string& args);
        void noValueLongParse(std::string& args);
        void noValueShortParse(std::string& args);
        void valueParse(std::string& args);
        void valueLongParse(std::string& args);
        void valueShortParse(std::string& args);
    };

    template<class T>
    RawParseOption<T>::RawParseOption(const std::string& option) :
            longOption(option),
            shortOption(option[0]),
            takesValue(false) {
    }

    template<class T>
    RawParseOption<T>::RawParseOption(char shortOpt, std::string longOpt) :
            shortOption(shortOpt),
            longOption(std::move(longOpt)),
            takesValue(false) {
    }

    template<class T>
    RawParseOption<T>::RawParseOption(const std::string& option, bool takesValue) :
            shortOption(option[0]),
            longOption(option),
            takesValue(takesValue) {
    }

    template<class T>
    RawParseOption<T>::RawParseOption(char shortOpt, std::string longOpt, bool takesValue) :
            shortOption(shortOpt),
            longOption(std::move(longOpt)),
            takesValue(false) {
    }

    template<class T>
    T RawParseOption<T>::getValue() {
        if (value == nullptr) {
            throw ParseOptionEmptyException(takesValue);
        }
        return *transmutingFunction(value);
    }

    template<class T>
    MatchResult RawParseOption<T>::match(std::string& args) {
        found = false;
        if (takesValue) {
            valueParse(args);
        } else {
            noValueParse(args);
        }
        return MatchResult(found, args);
    }

    template<class T>
    void RawParseOption<T>::valueParse(std::string& args) {
        valueLongParse(args);
        if (!found && acceptShortOption) {
            valueShortParse(args);
        }
    }

    template<class T>
    void RawParseOption<T>::valueShortParse(std::string& args) {
        const auto& matchSequence = std::string({separatorSpace, shortOptNotation, shortOption, separatorSpace});
        size_t shortPos = args.find(matchSequence);
        unless (shortPos == -1) {
            found = true;
            ++appeared;
            // Switch data
            const auto shortStart = 0 + shortPos + 1;
            const auto shortEnd = shortStart + shortOptNotationLen + 1;
            const auto shortLength = shortEnd - shortStart;
            // Argument data
            const auto spaceStart = args.find(' ', shortEnd) + 1;
            const auto spaceEnd = args.find(' ', spaceStart + 1);
            const auto spaceLength = spaceEnd - spaceStart + 1;
            value = new T(static_cast<T>(args.substr(spaceStart, spaceLength)));
            args.erase(shortStart, shortLength + spaceLength);
        }
    }

    template<class T>
    void RawParseOption<T>::valueLongParse(std::string& args) {
        size_t longPos = args.find(longOptNotation + longOption);
        unless (longPos == -1) {
            found = true;
            ++appeared;
            const auto longStart = 0 + longPos;
            const auto longEnd = longStart + longOptNotationLen + longOption.length();
            const auto spaceStart = args.find_first_of(' ', longEnd) + 1;
            const auto spaceEnd = args.find_first_not_of(' ', spaceStart);
            value = new T(static_cast<T>(args.substr(spaceStart, spaceEnd - spaceStart)));
        }
    }

    template<class T>
    void RawParseOption<T>::noValueParse(std::string& args) {
        noValueLongParse(args);
        if (!found && acceptShortOption) {
            noValueShortParse(args);
        }
    }

    template<class T>
    void RawParseOption<T>::noValueShortParse(std::string& args) {
        const auto& matchSequence = std::string({separatorSpace, shortOptNotation, shortOption, separatorSpace});
        size_t shortPos = args.find(matchSequence);
        unless (shortPos == -1) {
            found = true;
            ++appeared;
            auto shortStart = 0 + shortPos + 1;
            const auto shortEnd = shortStart + shortOptNotationLen + 1;
            const auto shortLength = shortEnd - shortStart;
            args.erase(shortStart, shortLength);
        }
    }

    template<class T>
    void RawParseOption<T>::noValueLongParse(std::string& args) {
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
    const std::string& RawParseOption<T>::getLongOption() const {
        return longOption;
    }

    template<class T>
    bool RawParseOption<T>::doesAcceptShortOption() const {
        return acceptShortOption;
    }

    template<class T>
    void RawParseOption<T>::setAcceptShortOption(bool acceptShortOption) {
        RawParseOption::acceptShortOption = acceptShortOption;
    }

    template<class T>
    RawParseOption<T>::~RawParseOption() {
        delete value;
        value = nullptr;
    }

    template<class T>
    bool RawParseOption<T>::isTakesValue() const {
        return takesValue;
    }
}
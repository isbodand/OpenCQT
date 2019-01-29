#include <utility>

#pragma once

#include <string>
#include <utility>
#include <optional>
#include <vector>
#include <cstring>
#include <functional>

#include "../MatchResult.hpp"
#include "../utils.hpp"
#include "../ParseOptionEmptyException.hpp"

namespace InfoParse {

    static const char* const longOptNotation = "--";

    static const size_t longOptNotationLen = 2;

    static const char shortOptNotation = '-';

    static const size_t shortOptNotationLen = 1;

    static const char separatorSpace = ' ';

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

        virtual ~ParseOption();

        /**
         * Returns current value of the ParseOption
         * throws ParseOptionEmptyException if empty
         */
        T getValue();

        const std::string& getOptionName() const;

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

    private:
        void noValueParse(std::string& args);
        void noValueLongParse(std::string& args);
        void noValueShortParse(std::string& args);
        void valueParse(std::string& args);
        void valueLongParse(std::string& args);
        void valueShortParse(std::string& args);
    };

    template<>
    class ParseOption<bool> {
        std::string longOption;
        char shortOption;
        bool acceptShortOption = true;

        bool found = false;
        long appeared = 0;
        bool val = false;

    public:
        explicit ParseOption(const std::string& option);
        ParseOption(char shortOpt, std::string longOpt);

        bool getValue();

        const std::string& getOptionName() const;

        virtual ~ParseOption() = default;

        bool isTakesValue();

        MatchResult match(const std::string& args);
    private:
        void longParse(std::string& args);

        void shortParse(std::string& args);

        void shortBulkParse(std::string& args);

        void shortBareParse(std::string& args);
    };

    ParseOption<bool>::ParseOption(const std::string& option) :
            longOption(option),
            shortOption(option[0]) {
    }

    ParseOption<bool>::ParseOption(char shortOpt, std::string longOpt) :
            shortOption(shortOpt),
            longOption(std::move(longOpt)) {
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
    MatchResult ParseOption<T>::match(std::string& args) {
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
    void ParseOption<T>::valueShortParse(std::string& args) {
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
    void ParseOption<T>::valueLongParse(std::string& args) {
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
    void ParseOption<T>::noValueParse(std::string& args) {
        noValueLongParse(args);
        if (!found && acceptShortOption) {
            noValueShortParse(args);
        }
    }

    template<class T>
    void ParseOption<T>::noValueShortParse(std::string& args) {
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
    const std::string& ParseOption<T>::getOptionName() const {
        return longOption;
    }

    template<class T>
    bool ParseOption<T>::doesAcceptShortOption() const {
        return acceptShortOption;
    }

    template<class T>
    void ParseOption<T>::setAcceptShortOption(bool acceptShortOption) {
        this->acceptShortOption = acceptShortOption;
    }

    template<class T>
    ParseOption<T>::~ParseOption() {
        delete value;
        value = nullptr;
    }

    MatchResult ParseOption<bool>::match(const std::string& args) {
        found = false;
        std::string argsToParse = args;
        longParse(argsToParse);
        unless (found) {
            shortParse(argsToParse);
        }
        return MatchResult(found, argsToParse);
    }

    void ParseOption<bool>::longParse(std::string& args) {
        size_t longPos = args.find(longOptNotation + longOption);
        unless (longPos == -1) {
            found = true;
            ++appeared;
            const auto longStart = args.begin() + longPos;
            const auto longEnd = longStart + (longOption.length() + 2);
            args.erase(longStart, longEnd);
        }
    }

    void ParseOption<bool>::shortParse(std::string& args) {
        shortBareParse(args);
        unless (found) {
            shortBulkParse(args);
        }
    }

    void ParseOption<bool>::shortBareParse(std::string& args) {
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

    void ParseOption<bool>::shortBulkParse(std::string& args) {
        const auto& bulkSequence = std::string({separatorSpace, shortOptNotation});
        size_t startSearch = 0;
        bool foundBulk = false;
        size_t bulkStart = 0;
        size_t bulkEnd = 0;

        do {
            size_t possibleBulkStart = args.find(bulkSequence, startSearch);
            size_t possibleBulkEnd = args.find(' ', possibleBulkStart + 1);
            foundBulk = possibleBulkEnd - possibleBulkStart > 2;
            startSearch = possibleBulkEnd + 1;
        } until (foundBulk || startSearch >= args.length());

        if (foundBulk) {
            //todo
        }
    }

    bool ParseOption<bool>::isTakesValue() { return true; }

    const std::string& ParseOption<bool>::getOptionName() const { return longOption; }

    bool ParseOption<bool>::getValue() { return val; }

    template<class T>
    bool ParseOption<T>::isTakesValue() const { return takesValue; }
}

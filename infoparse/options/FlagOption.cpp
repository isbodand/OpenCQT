#include "FlagOption.hpp"
#include "../MatchResult.hpp"

InfoParse::MatchResult InfoParse::FlagOption::match(std::string& args) {
    found = false;
    std::string argsParse = args;
    noValueParse(argsParse);
    return InfoParse::MatchResult(found, argsParse);
}

void InfoParse::FlagOption::noValueParse(std::string& args) {
    noValueLongParse(args);
    if (!found && acceptShortOption) {
        noValueShortParse(args);
    } else if (!found && acceptShortOption) {
        const auto& bundleStartSequence = std::string({InfoParse::separatorSpace, InfoParse::shortOptNotation});
        size_t bundleStart = args.find(bundleStartSequence);
    }
}

void InfoParse::FlagOption::noValueShortParse(std::string& args) {
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

void InfoParse::FlagOption::noValueLongParse(std::string& args) {
    size_t longPos = args.find(longOptNotation + longOption);
    unless (longPos == -1) {
        found = true;
        ++appeared;
        const auto longStart = args.begin() + longPos;
        const auto longEnd = longStart + (longOption.length() + 2);
        args.erase(longStart, longEnd);
    }
}

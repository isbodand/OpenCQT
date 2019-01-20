//
// Created by bodand on 2019-01-20.
//

#include "MatchResult.hpp"

InfoParse::MatchResult::MatchResult(bool success, std::string res)
        : successful(success),
          resultString(std::move(res)) {
}

bool InfoParse::MatchResult::isSuccessful() const {
    return successful;
}

const std::string& InfoParse::MatchResult::getResultString() const {
    return resultString;
}


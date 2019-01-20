//
// Created by bodand on 2019-01-20.
//

#pragma once

#include <string>

namespace InfoParse {

    class MatchResult {
        bool successful;
        std::string resultString;

    public:
        MatchResult(bool success, std::string res);

        bool isSuccessful() const;
        const std::string& getResultString() const;
    };
}

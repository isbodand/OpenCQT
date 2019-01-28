#pragma once

namespace InfoParse {
    class FlagOption : public ParseOption<bool> {
        MatchResult match(std::string& args) override;

        private:
            void noValueParse(std::string& args);
            void noValueShortParse(std::string& args);
            void noValueLongParse(std::string& args);
    }
}

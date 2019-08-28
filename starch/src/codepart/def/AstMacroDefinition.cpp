//
// Created by bodand on 2019-08-24.
//

#include <algorithm>
//#include <execution>
#include <utility>
#include <boost/algorithm/string/replace.hpp>

#include "AstMacroDefinition.hpp"

int LibStarch::ASTMacroDefinition::getType() const {
    return 0;
}

void LibStarch::ASTMacroDefinition::accept(LibStarch::Visiting::Visitor& visitor) {
    visitor.visit(*this);
}

std::string&& LibStarch::ASTMacroDefinition::apply(const std::vector<std::string>& args) const {
    std::string ret(text);
    std::vector<std::string>::size_type i = 0;
    std::for_each(args.begin(), args.end(), [ret, i, this](const std::string& arg) mutable {
      boost::algorithm::replace_all(ret, "${" + params[i] + "}", arg);
      ++i;
    });

    return std::move(ret);
}


LibStarch::ASTMacroDefinition::ASTMacroDefinition(const LibStarch::ValID& name, std::string text,
                                                  std::vector<std::string> params)
     : ASTDefinition(name),
       params(std::move(params)),
       text(std::move(text)) {}

const std::string& LibStarch::ASTMacroDefinition::getText() const {
    return text;
}



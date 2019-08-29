//
// Created by bodand on 2019-06-12.
//

#pragma once

#include <algorithm>
#include <numeric>

#include <boost/spirit/include/qi.hpp>

#include "../../starch/starch.hpp"

namespace OpenCqt::Parse {
  namespace qi = boost::spirit::qi;
  namespace ascii = boost::spirit::ascii;
  namespace sch = LibStarch;

  template<class It>
  struct CroquetteGrammar
       : qi::grammar<It, sch::ASTRoot(), ascii::space_type> {

      CroquetteGrammar()
           : CroquetteGrammar::base_type(main) {
          using qi::int_;
          using qi::lit;
          using qi::double_;
          using qi::lexeme;
          using ascii::char_;
          using qi::_val;

          valText %= lexeme['"' >> +(char_ - '"') >> '"'][sch::ValText(vectostr(_val))];

      }

      qi::rule<It, sch::ASTRoot> main;

      qi::rule<It, sch::ValText()> valText;
      qi::rule<It, sch::ValNumber()> valNum;
      qi::rule<It, sch::ValID()> valId;
      qi::rule<It, sch::ValExpr()> valExpr;

      std::string vectostr(const std::vector<char>& vec);
  };

  template<class It>
  std::string CroquetteGrammar<It>::vectostr(const std::vector<char>& vec) {
      return std::accumulate(vec.begin(), vec.end(), std::string());
  }
}

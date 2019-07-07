//
// Created by bodand on 2019-06-12.
//

#pragma once

#include <boost/spirit/include/qi.hpp>

namespace OpenCqt::Parse {
  namespace qi = boost::spirit::qi;
  namespace ascii = boost::spirit::ascii;

  template<class Iterator>
  struct CroquetteGrammar
          : qi::grammar<Iterator, void(), ascii::space_type> {

  };
}

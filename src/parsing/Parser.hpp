//
// Created by tudom on 2019-06-12.
//

#pragma once

namespace OpenCqt::Parse {
  template<class Grammar>
  class Parser {
      Grammar grammar;
  public: // Methods

  public: // Constructors & Destructor
      Parser() = default;
      Parser(const Parser& cp) = default;
      Parser(Parser&& mv) noexcept = default;

      virtual ~Parser() = default;

  public: // Operators
      Parser& operator=(const Parser& cp) = default;
      Parser& operator=(Parser&& mv) noexcept = default;
  };

}

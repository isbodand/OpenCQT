//
// Created by bodand on 2019-06-20.
//

#pragma once

#include <string>
#include <ostream>
#include "ValNode.hpp"

namespace LibStarch {
  class ValID : public ValNode {
  public: // Methods
      const std::string& getIdName() const;
      double eval() const override;
      void asString(std::ostream& os) const override;
      void accept(Visiting::Visitor& visitor) override;

  public: // Constructors & Destructor
      ValID(std::string idName);
      ValID(const char* idName);
      ValID(const ValID& cp) = default;
      ValID(ValID&& mv) noexcept = default;

      virtual ~ValID() = default;

  public: // Operators
      ValID& operator=(const ValID& cp) = default;
      ValID& operator=(ValID&& mv) noexcept = default;

  private: // Private methods
      ValID() = default;

  private: // Fields
      std::string idName;
  };
}



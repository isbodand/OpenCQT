//
// Created by bodand on 2019-04-01.
//

#pragma once

#include "../archetypes/HashArchetype.hpp"

namespace LibCqt {
  class OrderedMapType : public HashArchetype<Map> {
  public: // Types
      using T = Map<String, AnyArchetype_P>;
      using U = void;
      using Archetype = HashArchetype<Map>;
      using _Archetype = HashArchetype;

  protected: // Overridden protected methods
      String printStart() const override;

  public: // Constructors & destructor
      OrderedMapType() = default;
      OrderedMapType(OrderedMapType& cp) = default;
      OrderedMapType(OrderedMapType&& mv) noexcept = default;
      explicit OrderedMapType(const Ptr <OrderedMapType>& ptrCopy);
      OrderedMapType(HashArchetype <Map>& cpa);

  public: // Operators
      OrderedMapType& operator=(OrderedMapType& cp) = default;
      OrderedMapType& operator=(OrderedMapType&& mv) noexcept = default;
  };
}



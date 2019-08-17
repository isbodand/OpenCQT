//
// Created by bodand on 2019-03-25.
//

#pragma once

#include <ostream>
#include <vector>
#include <memory>
#include <type_traits>
#include <codecvt>
#include <locale>
#include "../../uniprint.hpp"
#include "../ImplementationTypes.hpp"

namespace LibCqt {
  /**
   * Decides whether the AnyArchetype
   * is which Archetype is currently.
   * Used when types decay down to AnyArchetype
   */
  typedef enum _ArchetypeType {
      archScalar,
      archArray,
      archHash,
      archReference
  } ArchetypeType;

  typedef enum _ScalarType {
      scalarAnyScalar,
      scalarCharacterScalar,
      scalarTrueScalar
  } ScalarType;

  typedef enum _ArrayType {
      arrayAnyArray,
      arrayFlatArray,
      arrayComplexArray
  } ArrayType;

  typedef enum _HashType {
      hashAnyHash,
      hashOrderedHash,
      hashUnorderedHash
  } HashType;

  typedef enum _ReferenceType {
      refAnyReference,
      refLocalReference,
      refGlobalReference
  } ReferenceType;

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /**
   * AnyArchetype
   * Represents any kind of cell in
   * the Croquette ecosystem.
   */
  class AnyArchetype {
      // Values
      ArchetypeType currentType;
  public: // Types
      using T = void;
      using U = void;
      using Archetype = AnyArchetype;
      using _Archetype = AnyArchetype;

  public: // Virtual methods
      /**
       * Returns a printable string representation
       * of the value.
       * @return For AnyArchetypes directly it is undefined behavior;
       *         currently OpenCQT returns a warning for invoking such UB.
       */
      virtual String asString() const;

      virtual ScalarType getScalarType() const;
      virtual ArrayType getArrayType() const;
      virtual HashType getHashType() const;
      virtual ReferenceType getReferenceType() const;

  public: // Constructors & destructor
      /**
       * Default Constructor for AnyArchetype
       * Sets ArchetypeType to Scalar.
       */
      AnyArchetype();
      /**
       * Constructs the inner ArchetypeType to be
       * the specified value.
       * @param currentType The value to create the inner
       *                    ArchetypeType as.
       */
      explicit AnyArchetype(ArchetypeType currentType);
      /**
       * Const Copy Constructor
       * Default
       */
      AnyArchetype(const AnyArchetype& cp) = default;
      /**
       * Move Constructor
       * Default
       */
      AnyArchetype(AnyArchetype&& mv) noexcept = default;

      /**
       * Destructor
       * Default
       */
      virtual ~AnyArchetype() = default;

  public: // Operators
      /**
       * Copy assignment
       * Default
       */
      AnyArchetype& operator=(AnyArchetype& cp) = default;
      /**
       * Move assignment
       * Default
       */
      AnyArchetype& operator=(AnyArchetype&& mv) noexcept = default;
      /**
       * Checks equality based on ArchetypeType
       * @param rhs The other AnyArchetype to be compared against
       * @return Whether the ArchetypeTypes match
       */
      bool operator==(const AnyArchetype& rhs) const;
      /**
       * Check inequality based on ArchetypeType
       * @param rhs The other AnyArchetype to be compared against
       * @return Whether the ArchetypeTypes don't match
       */
      bool operator!=(const AnyArchetype& rhs) const;

      /**
       * Friend method for <<-ing into ostream
       * @param os The ostream to << into
       * @param archetype The AnyArchetype instance
       * @return The ostream into which the archetype has been <<-d
       *
       * @see std::wostream& operator<<(std::wostream&, const AnyArchetype&);
       */
      friend std::ostream& operator<<(std::ostream& os, const AnyArchetype& archetype);
      /**
       * Friend method for <<-ing into wostream
       * @param os The wostream to << into
       * @param archetype The AnyArchetype instance
       * @return The wostream into which the archetype has been <<-d
       *
       * @see std::ostream& operator<<(std::ostream&, const AnyArchetype&);
       */
      friend std::wostream& operator<<(std::wostream& os, const AnyArchetype& archetype);

  public: // Miscellaneous methods
      /**
       * Getter for the current ArchetypeType
       */
      ArchetypeType getCurrentType() const;
  };
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /// Pointer types
  using AnyArchetype_P = Ptr<AnyArchetype>;
  using AnyArchetype_R = AnyArchetype*;
}


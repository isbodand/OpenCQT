//
// Created by bodand on 2019-03-25.
//

#pragma once

#include <vector>
#include <memory>
#include <type_traits>
#include <ostream>
#include <codecvt>
#include <locale>

#include "../ImplementationTypes.hpp"
#include "AnyArchetype.hpp"
#include "ScalarArchetype.hpp"
#include "../user_types/casts/ScalarCast.hpp"

namespace LibCqt {

  /**
   * Array of cells
   * Stores an arbirary amount of arbitrary cells.
   *
   * @tparam ConT The type of Cells this array stores. AnyArchetype for all.
   *              Default is ScalarArchetype.
   * @tparam DefT The type to initialize new cells as. Default equals to ConT,
   *              however, all implemented subtypes differentiate these.
   * @tparam _1 Don't bother
   * @tparam _2 Just no
   *
   * @see ScalarArchetype
   */
  template<class ConT = ScalarArchetype, class DefT = ConT,
          typename _1 = typename std::enable_if_t<std::is_default_constructible_v<ConT>>,
          typename _2 = typename std::enable_if_t<std::is_same_v<String,
                  decltype(std::declval<ConT>().asString())>>
  >
  class ArrayArchetype : public AnyArchetype {
  public: // Types
      using T = ConT;
      using U = DefT;
      using Archetype = ArrayArchetype<T, U>;
      using _Archetype = ArrayArchetype;

  protected: // Values
      std::vector<Ptr<ConT>> cells;

  public: // Overridden methods
      /**
       * Returns a printable string representation
       * of the value.
       * @return Between the values of the protected virtual printStart (def: "$(")
       *         and the protected virtual printEnd (def: ")") each elements'
       *         own asString representation, separated by a comma.
       */
      String asString() const override;
      /**
       * Returns the ArrayType value corresponding
       * to the actual type of Array
       */
      virtual ArrayType getArrayType() const override;

  protected: // Virtual protected methods
      virtual String printStart() const;
      virtual String printEnd() const;

  protected: // Miscellaneous protected methods
      template<class _T, class _U = _T>
      explicit ArrayArchetype(Raw<ArrayArchetype<_T, _U>> ptr);

  public: // Constructors & destructor
      /**
       * Default constructor
       * Instantiates AnyArchetype with Array ArchetypeType
       * and sets the current cells to nothing.
       */
      ArrayArchetype();
      /**
       * Instantiates AnyArchetype to Array ArchetypeType
       * and the cells array to init
       * @param init The initializer_list of starter values
       *             for the ConT typed cells.
       */
      ArrayArchetype(std::initializer_list<Ptr<ConT>> init);
      /**
       * Instantiates AnyArchetype to Array ArchetypeType
       * and the cells array to init
       * @param init The std::vector of starter values
       *             for the ConT typed cells.
       */
      ArrayArchetype(std::vector<Ptr<ConT>> init);
      /**
       * Const Copy Constructor
       * Default
       */
      ArrayArchetype(CRf<ArrayArchetype> cp) = default;
      /**
       * Move Constructor
       * Default
       */
      ArrayArchetype(RRf<ArrayArchetype> mv) noexcept = default;
      /**
       * Copies the values from a Ptr<> to
       * the value to be copied.
       * @tparam _T ConT of the other Array
       * @tparam _U DefT of the other Array
       * @param ptr The Ptr<> to the other Array
       *
       * @see Ptr<T> in ImplementationTypes.hpp
       */
      template<class _T, class _U = _T>
      explicit ArrayArchetype(CRf<Ptr<ArrayArchetype<_T, _U>>> ptr);

      /**
       * Destructor
       * Default
       */
      virtual ~ArrayArchetype() = default;

  public: // Operators
      /**
       * Copy Assignment
       * Default
       */
      ArrayArchetype& operator=(Ref<ArrayArchetype> cp) = default;
      /**
       * Move Assignment
       * Default
       */
      ArrayArchetype& operator=(RRf<ArrayArchetype> mv) noexcept = default;

      /**
       * Checks equality of Array by checking length,
       * then each element individually.
       * Also checks whether ArrayTypes match.
       *
       * @param rhs Other Array to check with
       * @return Whether the Arrays equal
       */
      bool operator==(const ArrayArchetype& rhs) const;
      /**
       * Checks inequality of Array by checking length,
       * then each element individually.
       * @param rhs Other Array to check with
       * @return Whether the Arrays don't equal
       */
      bool operator!=(const ArrayArchetype& rhs) const;

      /**
       * Returns a reference to the at-th element
       *
       * @param at The index of the item to return the reference to.
       */
      Ref<Ptr<ConT>> operator[](std::size_t at);

  public: // Miscellaneous methods
      /**
       * Creates a new element of type DefT in the Array
       * @return The new length of the Array
       */
      std::size_t makeCell();
      /**
       * Creates a new element of type DefT in the Array
       * using the given arguments for the construction
       * @param args The arguments to be given to the
       *             newly instantialized element's constructor
       * @return The new length of the Array
       */
      template<class... Args>
      std::size_t makeCell(Args... args);

      /**
       * Creates a new element of type C in the Array
       * @tparam C The type of the new element so that:
       *           `C <: ConT` (allows `C = ConT`)
       *           and C is default constuctible
       * @return The new length of the Array
       */
      template<class C>
      ENABLE_IF std::is_default_constructible_v<C>
                && (std::is_same_v<C, ConT> || std::is_base_of_v<ConT, C>)THEN
      (std::size_t) makeCellOfType();
      /**
       * Creates a new element of type C in the Array
       * using the given arguments for the construction
       * @tparam C The type of the new element so that:
       *           `C <: ConT` (allows `C = ConT`)
       *           and C is constructable using Args
       * @return The new length of the Array
       */
      template<class C,
              class... Args>
      ENABLE_IF std::is_constructible_v<C, Args...>
                && (std::is_same_v<C, ConT> || std::is_base_of_v<ConT, C>)THEN
      (std::size_t) makeCellOfType(Args... args);

      /**
       * Returns the Ptr<> to the at-th element cast into
       * type R.
       * SFINAE-d Archetypes of ConT and R equal to ScalarArchetype
       *
       * @tparam R The type to get the at-th element as
       * @param at The index of the item to return
       * @return The Ptr<R> of the at-th element
       */
      template<class R = DefT>
      Ptr<R> getAs(size_t at);

      /**
       * Length of the Array
       */
      std::size_t size();

      /**
       * Trivial getter
       * Returns a const reference to the current
       * vector of Ptr<>-s to cells in the Array.
       */
      CRf<std::vector<Ptr<ConT>>> getCells() const;
  };
  /////////////////////////////////////////////////////////////////////////////////////////////////
    /// Pointer types
    template<class T = ScalarArchetype, class U = T>
    using ArrayArchetype_P = Ptr<ArrayArchetype<T, U>>;
    template<class T = ScalarArchetype, class U = T>
    using ArrayArchetype_R = Raw<ArrayArchetype<T, U>>;
}

template<class T, class U, typename _1, typename _2>
inline LibCqt::ArrayArchetype<T, U, _1, _2>::ArrayArchetype() : AnyArchetype(LibCqt::archArray), cells(0) {}

template<class T, class U, typename _1, typename _2>
inline LibCqt::ArrayArchetype<T, U, _1, _2>::ArrayArchetype(std::initializer_list<Ptr<T>> init)
        : AnyArchetype(LibCqt::archArray), cells(init) {
}

template<class T, class U, typename _1, typename _2>
inline LibCqt::ArrayArchetype<T, U, _1, _2>::ArrayArchetype(std::vector<Ptr<T>> init)
        : AnyArchetype(LibCqt::archArray), cells(init) {
}

template<class T, class U, typename _1, typename _2>
inline std::size_t LibCqt::ArrayArchetype<T, U, _1, _2>::makeCell() {
    cells.push_back(mkPtr<U>());
    return cells.size();
}

template<class T, class U, typename _1, typename _2>
template<class... Args>
//todo fixme; why?
inline std::size_t LibCqt::ArrayArchetype<T, U, _1, _2>::makeCell(Args... args) {
    cells.push_back(mkPtr<U>(args...));
    return cells.size();
}

template<class T, class U, typename _1, typename _2>
template<class C>
inline ENABLE_IF std::is_default_constructible_v<C>
                 && (std::is_same_v<C, T> || std::is_base_of_v<T, C>)THEN
(std::size_t) LibCqt::ArrayArchetype<T, U, _1, _2>::makeCellOfType() {
    cells.push_back(mkPtr<C>());
    return cells.size();
}

template<class T, class U, typename _1, typename _2>
template<class C, class... Args>
inline ENABLE_IF std::is_constructible_v<C, Args...>
                 && (std::is_same_v<C, T> || std::is_base_of_v<T, C>)THEN
(std::size_t) LibCqt::ArrayArchetype<T, U, _1, _2>::makeCellOfType(Args... args) {
    cells.push_back(mkPtr<C>(args...));
    return cells.size();
}

template<class T, class U, typename _1, typename _2>
inline LibCqt::String LibCqt::ArrayArchetype<T, U, _1, _2>::asString() const {
    StringStream stream;
    stream << printStart();
    for (auto i = this->cells.begin(); i != cells.end(); ++i != cells.end() && stream << CQT_STRING(", ")) {
        stream << (*i)->asString();
    }
    stream << printEnd();
    return std::move(stream.str());
}

template<class T, class U, typename _1, typename _2>
inline LibCqt::Ref<LibCqt::Ptr<T>> LibCqt::ArrayArchetype<T, U, _1, _2>::operator[](std::size_t at) {
    return cells[at];
}

template<class T, class U, typename _1, typename _2>
inline std::size_t LibCqt::ArrayArchetype<T, U, _1, _2>::size() {
    return cells.size();
}

template<class T, class U, typename _1, typename _2>
template<class _T, class _U>
inline LibCqt::ArrayArchetype<T, U, _1, _2>::ArrayArchetype(CRf<LibCqt::Ptr<LibCqt::ArrayArchetype<_T, _U>>> ptr)
        : ArrayArchetype(*ptr) {
}

template<class T, class U, typename _1, typename _2>
inline LibCqt::CRf<std::vector<LibCqt::Ptr<T>>> LibCqt::ArrayArchetype<T, U, _1, _2>::getCells() const {
    return cells;
}

template<class T, class U, typename _1, typename _2>
template<class _T, class _U>
inline LibCqt::ArrayArchetype<T, U, _1, _2>::ArrayArchetype(LibCqt::Raw<LibCqt::ArrayArchetype<_T, _U>> ptr)
        : ArrayArchetype(*ptr) {
}

template<class T, class U, typename _1, typename _2>
inline LibCqt::String LibCqt::ArrayArchetype<T, U, _1, _2>::printStart() const {
    return CQT_STRING("$(");
}

template<class T, class U, typename _1, typename _2>
inline LibCqt::String LibCqt::ArrayArchetype<T, U, _1, _2>::printEnd() const {
    return CQT_STRING(")");
}

template<class ConT, class DefT, typename _1, typename _2>
inline bool LibCqt::ArrayArchetype<ConT, DefT, _1, _2>::operator==(const ArrayArchetype& rhs) const {
    if (getArrayType() != rhs.getArrayType())
        return false;

    if (rhs.cells.size() != cells.size())
        return false;

    bool eq = true;
    int i = 0;
    while (eq && i < cells.size()) {
        eq = *cells[i] == *rhs.cells[i];
        i++;
    }
    eq = eq && i == cells.size();

    return static_cast<const AnyArchetype&>(*this) == static_cast<const AnyArchetype&>(rhs) &&
           eq;
}

template<class ConT, class DefT, typename _1, typename _2>
inline bool LibCqt::ArrayArchetype<ConT, DefT, _1, _2>::operator!=(const ArrayArchetype& rhs) const {
    return !(rhs == *this);
}

template<class ConT, class DefT, typename _1, typename _2>
LibCqt::ArrayType LibCqt::ArrayArchetype<ConT, DefT, _1, _2>::getArrayType() const {
    return arrayAnyArray;
}

template<class ConT, class DefT, typename _1, typename _2>
template<class R>
LibCqt::Ptr<R> LibCqt::ArrayArchetype<ConT, DefT, _1, _2>::getAs(size_t at) {
    // note: static_pointer_cast doesn't work
    return mkPtr<R>(*static_cast<R*>(cells[at].get()));
}

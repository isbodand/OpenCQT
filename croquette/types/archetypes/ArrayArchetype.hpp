//
// Created by bodand on 2019-03-25.
//

#pragma once

#include <vector>
#include <memory>
#include <type_traits>

#include "../ImplementationTypes.hpp"
#include "AnyArchetype.hpp"
#include "ScalarArchetype.hpp"

namespace LibCqt {
    template<class T = ScalarArchetype, class U = T,
             typename _1 = typename std::enable_if_t<std::is_default_constructible_v<T>>,
             typename _2 = typename std::enable_if_t<std::is_same_v<String,
                                                                    decltype(std::declval<T>().asString())>>
            >
    class ArrayArchetype : public AnyArchetype {
    protected:
        std::vector<Ptr<T>> cells;
        virtual String printStart();
        virtual String printEnd();

        template<class _T, class _U = _T>
        explicit ArrayArchetype(Raw<ArrayArchetype<_T, _U>> ptr);
    public:
        ArrayArchetype();
        ArrayArchetype(std::initializer_list<Ptr<AnyArchetype>> init);
        template<class _T, class _U = _T>
        explicit ArrayArchetype(const ArrayArchetype<_T, _U>& ptr);
        template<class _T, class _U = _T>
        explicit ArrayArchetype(const Ptr<ArrayArchetype<_T, _U>>& ptr);
        virtual ~ArrayArchetype();

        std::size_t makeCell();

        template<class... Args>
        std::size_t makeCell(Args... args);

        template<class C,
                 typename __1 = typename std::enable_if_t<std::is_default_constructible_v<C>>,
                 typename __2 = typename std::enable_if_t<std::is_same_v<C, T> || std::is_base_of_v<C, T>>>
        std::size_t makeCellOfType();

        template<class C,
                 class... Args>
        std::enable_if_t<std::is_constructible_v<C, Args...>,
                         std::size_t> makeCellOfType(Args... args);

        String asString() override;

        Ptr<T> operator[](std::size_t at);

        template<class R = U>
        Ptr<R> getAs(size_t at);

        std::size_t size();

        const std::vector<Ptr<T>>& getCells() const;
    };
}

template<class T, class U, typename _1, typename _2>
LibCqt::ArrayArchetype<T, U, _1, _2>::ArrayArchetype() : AnyArchetype(LibCqt::Array), cells(0) {}

template<class T, class U, typename _1, typename _2>
LibCqt::ArrayArchetype<T, U, _1, _2>::ArrayArchetype(std::initializer_list<Ptr<AnyArchetype>> init)
        : AnyArchetype(LibCqt::Array), cells(init) {
}

template<class T, class U, typename _1, typename _2>
std::size_t LibCqt::ArrayArchetype<T, U, _1, _2>::makeCell() {
    cells.push_back(mkPtr<U>());
    return cells.size();
}

template<class T, class U, typename _1, typename _2>
template<class... Args>
//todo fixme
std::size_t LibCqt::ArrayArchetype<T, U, _1, _2>::makeCell(Args... args) {
    cells.push_back(mkPtr<U>(args...));
    return cells.size();
}

template<class T, class U, typename _1, typename _2>
template<class C, typename __1, typename __2>
std::size_t LibCqt::ArrayArchetype<T, U, _1, _2>::makeCellOfType() {
    cells.push_back(mkPtr<C>());
    return cells.size();
}

template<class T, class U, typename _1, typename _2>
template<class C, class... Args>
std::enable_if_t<std::is_constructible_v<C, Args...>,
                 std::size_t> LibCqt::ArrayArchetype<T, U, _1, _2>::makeCellOfType(Args... args) {
    cells.push_back(mkPtr<C>(args...));
    return cells.size();
}

template<class T, class U, typename _1, typename _2>
LibCqt::String LibCqt::ArrayArchetype<T, U, _1, _2>::asString() {
    StringStream stream;
    stream << printStart();
    for (auto i = this->cells.begin(); i != cells.end(); ++i) {
        stream << (*i)->asString();
        if (i + 1 != cells.end()) {
            stream << CQT_STRING(", ");
        }
    }
    stream << printEnd();
    return std::move(stream.str());
}

template<class T, class U, typename _1, typename _2>
LibCqt::Ptr<T> LibCqt::ArrayArchetype<T, U, _1, _2>::operator[](std::size_t at) {
    return cells[at];
}

template<class T, class U, typename _1, typename _2>
LibCqt::ArrayArchetype<T, U, _1, _2>::~ArrayArchetype() {
}

template<class T, class U, typename _1, typename _2>
template<class R>
LibCqt::Ptr<R> LibCqt::ArrayArchetype<T, U, _1, _2>::getAs(size_t at) {
    return std::dynamic_pointer_cast<R>(cells[at]);
}

template<class T, class U, typename _1, typename _2>
std::size_t LibCqt::ArrayArchetype<T, U, _1, _2>::size() {
    return cells.size();
}

template<class T, class U, typename _1, typename _2>
template<class _T, class _U>
LibCqt::ArrayArchetype<T, U, _1, _2>::ArrayArchetype(const LibCqt::Ptr<LibCqt::ArrayArchetype<_T, _U>>& ptr)
        : ArrayArchetype(ptr->getCells()) {
}

template<class T, class U, typename _1, typename _2>
const std::vector<LibCqt::Ptr<T>>& LibCqt::ArrayArchetype<T, U, _1, _2>::getCells() const {
    return cells;
}

template<class T, class U, typename _1, typename _2>
template<class _T, class _U>
LibCqt::ArrayArchetype<T, U, _1, _2>::ArrayArchetype(const LibCqt::ArrayArchetype<_T, _U>& ptr)
        : ArrayArchetype(ptr.getCells()) {
}

template<class T, class U, typename _1, typename _2>
template<class _T, class _U>
LibCqt::ArrayArchetype<T, U, _1, _2>::ArrayArchetype(LibCqt::Raw<LibCqt::ArrayArchetype<_T, _U>> ptr)
        : ArrayArchetype(*ptr) {
}

template<class T, class U, typename _1, typename _2>
LibCqt::String LibCqt::ArrayArchetype<T, U, _1, _2>::printStart() {
    return CQT_STRING("$(");
}

template<class T, class U, typename _1, typename _2>
LibCqt::String LibCqt::ArrayArchetype<T, U, _1, _2>::printEnd() {
    return CQT_STRING(")");
}


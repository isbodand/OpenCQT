//
// Created by bodand on 2019-03-25.
//

#pragma once

#include <vector>
#include <memory>
#include <type_traits>

#include "AnyArchetype.hpp"

namespace LibCqt {
    template<class T, class U = T,
             typename _1 = typename std::enable_if_t<std::is_default_constructible_v<T>>,
             typename _2 = typename std::enable_if_t<std::is_same_v<String,
                                                                    decltype(std::declval<T>().asString())>>
            >
    class ArrayArchetype : public AnyArchetype {
    protected:
        std::vector<std::shared_ptr<T>> cells;
        virtual String printStart() = 0;
        virtual String printEnd() = 0;

    public:
        ArrayArchetype();
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

        std::shared_ptr<T> operator[](std::size_t at);

        template<class R = U>
        std::shared_ptr<R> getAs(size_t at);
    };
}

template<class T, class U, typename _1, typename _2>
LibCqt::ArrayArchetype<T, U, _1, _2>::ArrayArchetype() : AnyArchetype(LibCqt::Array), cells(0) {}

template<class T, class U, typename _1, typename _2>
std::size_t LibCqt::ArrayArchetype<T, U, _1, _2>::makeCell() {
    cells.push_back(std::make_shared<U>());
    return cells.size();
}

template<class T, class U, typename _1, typename _2>
template<class... Args>
std::size_t LibCqt::ArrayArchetype<T, U, _1, _2>::makeCell(Args... args) {
    cells.push_back(std::make_shared<U>(args...));
    return cells.size();
}

template<class T, class U, typename _1, typename _2>
template<class C, typename __1, typename __2>
std::size_t LibCqt::ArrayArchetype<T, U, _1, _2>::makeCellOfType() {
    cells.push_back(std::make_shared<C>());
    return cells.size();
}

template<class T, class U, typename _1, typename _2>
template<class C, class... Args>
std::enable_if_t<std::is_constructible_v<C, Args...>,
                 std::size_t> LibCqt::ArrayArchetype<T, U, _1, _2>::makeCellOfType(Args... args) {
    cells.push_back(std::make_shared<C>(args...));
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
std::shared_ptr<T> LibCqt::ArrayArchetype<T, U, _1, _2>::operator[](std::size_t at) {
    return cells[at];
}

template<class T, class U, typename _1, typename _2>
LibCqt::ArrayArchetype<T, U, _1, _2>::~ArrayArchetype() {
}

template<class T, class U, typename _1, typename _2>
template<class R>
std::shared_ptr<R> LibCqt::ArrayArchetype<T, U, _1, _2>::getAs(size_t at) {
    return std::dynamic_pointer_cast<R>(cells[at]);
}



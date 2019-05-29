//
// Created by bodand on 2019-03-25.
//

#pragma once

#include "../archetypes/AnyArchetype.hpp"
#include "../archetypes/ArrayArchetype.hpp"
#include "TrueScalarType.hpp"

namespace LibCqt {
    class ComplexArrayType : public ArrayArchetype<AnyArchetype, TrueScalarType> {
    public: // Types
        using T = AnyArchetype;
        using U = TrueScalarType;
        using Archetype = ArrayArchetype<T, U>;

    public: // Overridden methods
        ArrayType getArrayType() const override;

    protected: // Overridden protected methods
        String printStart() const override;
        String printEnd() const override;

    public: // Constructors & destructor
        ComplexArrayType();
        ComplexArrayType(CRf<ComplexArrayType> cp) = default;
        ComplexArrayType(RRf<ComplexArrayType> mv) noexcept = default;
        explicit ComplexArrayType(CRf<Ptr<ComplexArrayType>> copy);
        ComplexArrayType(std::initializer_list<Ptr<T>> init);
        ComplexArrayType(std::vector<Ptr<T>> init);
        explicit ComplexArrayType(CRf<std::vector<Raw<T>>> init);
        ComplexArrayType(Ref<ArrayArchetype<T, U>> cpa);

        virtual ~ComplexArrayType() = default;

    public: // Operators
        ComplexArrayType& operator=(Ref<ComplexArrayType> cp) = default;
        ComplexArrayType& operator=(RRf<ComplexArrayType> mv) noexcept = default;


    };
}


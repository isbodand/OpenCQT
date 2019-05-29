//
// Created by bodand on 2019-03-25.
//

#pragma once

#include <ostream>
#include "../archetypes/ScalarArchetype.hpp"

namespace LibCqt {
    class TrueScalarType : public ScalarArchetype {
    public: // Type types
        using T = void;
        using U = void;
        using Archetype = ScalarArchetype;

    public: // Overridden methods
        ScalarType getScalarType() const override;

    public: // Constructors & destructor
        TrueScalarType();
        TrueScalarType(CRf<TrueScalarType> cp) = default;
        TrueScalarType(RRf<TrueScalarType> mv) noexcept = default;
        explicit TrueScalarType(double value);
        explicit TrueScalarType(CRf<Ptr<LibCqt::ScalarArchetype>> ref);
        TrueScalarType(Ref<ScalarArchetype> cpa);

        virtual ~TrueScalarType() = default;

    public: // Operators
        TrueScalarType& operator=(Ref<TrueScalarType> cp) = default;
        TrueScalarType& operator=(RRf<TrueScalarType> mv) noexcept = default;
        TrueScalarType& operator=(Ref<ScalarArchetype> cpa) noexcept override;
        TrueScalarType& operator=(RRf<ScalarArchetype> mva) noexcept override;
    };
}



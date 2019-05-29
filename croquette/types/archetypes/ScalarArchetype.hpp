//
// Created by bodand on 2019-03-25.
//

#pragma once

#include <ostream>
#include "AnyArchetype.hpp"
#include "../ImplementationTypes.hpp"

namespace LibCqt {

    class ScalarArchetype : public AnyArchetype {
    public: // Types
        using T = void;
        using U = void;
        using Archetype = ScalarArchetype;
        using _Archetype = ScalarArchetype;

    protected: // Values
        double value;

    public: // Overridden methods
        String asString() const override;
        virtual ScalarType getScalarType() const override;

    public: // Constructors & destructor
        ScalarArchetype();
        ScalarArchetype(CRf<ScalarArchetype> cp) = default;
        ScalarArchetype(RRf<ScalarArchetype> mv) noexcept = default;
        explicit ScalarArchetype(double value);
        explicit ScalarArchetype(CRf<Ptr<ScalarArchetype>> ref);

        virtual ~ScalarArchetype() = default;

    public: // Virtual operators
        virtual ScalarArchetype& operator=(Ref<ScalarArchetype> cp) = default;
        virtual ScalarArchetype& operator=(RRf<ScalarArchetype> mv) noexcept = default;

    public: // Operators
        bool operator==(const ScalarArchetype& rhs) const;
        bool operator!=(const ScalarArchetype& rhs) const;
        bool operator<(const ScalarArchetype& rhs) const;
        bool operator>(const ScalarArchetype& rhs) const;
        bool operator<=(const ScalarArchetype& rhs) const;
        bool operator>=(const ScalarArchetype& rhs) const;
        bool operator==(const double& rhs) const;
        bool operator!=(const double& rhs) const;
        bool operator<(const double& rhs) const;
        bool operator>(const double& rhs) const;
        bool operator<=(const double& rhs) const;
        bool operator>=(const double& rhs) const;

    public: // Miscellaneous methods
        double getValue() const;
        void setValue(double _value);
    };
    /// Pointer types
    using ScalarArchetype_P = Ptr<ScalarArchetype>;
    using ScalarArchetype_R = Raw<ScalarArchetype>;
}



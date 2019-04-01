//
// Created by bodand on 2019-03-25.
//

#pragma once

#include "../../uniprint.hpp"
#include "../ImplementationTypes.hpp"

namespace LibCqt {
    typedef enum _ArchetypeType {
        Scalar,
        Array,
        Hash,
        Reference
    } ArchetypeType;


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class AnyArchetype {
        ArchetypeType currentType;
    public:
        virtual String asString();
        AnyArchetype();
        explicit AnyArchetype(ArchetypeType currentType);

        ArchetypeType getCurrentType() const;
    };
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Pointer types
    using AnyArchetype_P = Ptr<AnyArchetype>;
    using AnyArchetype_R = Raw<AnyArchetype>;
}


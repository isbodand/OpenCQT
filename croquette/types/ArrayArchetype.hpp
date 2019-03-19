#pragma once

#include "Archetype.hpp"

#include <vector>

namespace LibCroquette {

class _ArrayArchetype : public ArcheType {
protected:
    ArcheType* elements;
    std::size_t size;
    std::size_t pointedAt = -1;

    _ArrayArchetype();
}

using ArrayArchetype = _ArrayArchetype;

} // LibCroquette

/*
 * InfoSoft Croquette Open Source implementation
 *
 *****************************************************************************
 * Copyright 2018 bodand && contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************
 *
 * Note:
 * The InfoSoft Croquette standard is not equivalent to this repository or its
 * code and is in no form related to the contents of the repository. Modifications
 * in the standard which were induced because of this repository and codebase
 * are merely coincidental and still do not mean a connection between the standard
 * and this code. `bodand` is the sole link between these two projects, as he
 * wishes to see his abomination come to life.
 */

// Parameter parser
#include "infoparse/OptionsParser.hpp"
// Croquette STD
#include "croquette/cqt.hpp"
#include "croquette/types/user_types/FlatArrayType.hpp"
#include "croquette/types/user_types/ComplexArrayType.hpp"
#include "croquette/types/archetypes/ArchetypeUtilities.hpp"
#include "croquette/types/user_types/CharacterScalarType.hpp"

namespace Cqt = LibCqt;

template<class R, class T, class U = T,
         typename = typename std::enable_if_t<std::is_base_of_v<Cqt::ArrayArchetype<T, U>, R>>>
void arbitrary() {
}

int main(int argc, char** argv) {
    Cqt::init();
    CQT_STDOUT << std::boolalpha;

    Cqt::ComplexArrayType array;
    array.makeCellOfType<Cqt::FlatArrayType>();
    for (int i = 0; i < 65; ++i) {
        array.getAs<Cqt::FlatArrayType>(0)->makeCell(i);
    }
    array.makeCellOfType<Cqt::CharacterScalarType>(
            Cqt::archetype_cast<Cqt::CharacterScalarType>(array.getAs<Cqt::FlatArrayType>(0))
                                                  );
    array.makeCellOfType<Cqt::FlatArrayType>(
            Cqt::archetype_cast<Cqt::FlatArrayType>(array.getAs<Cqt::CharacterScalarType>(1))
                                            );

    CQT_STDOUT << array.asString();

    return 0;
}


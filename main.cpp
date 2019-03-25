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
#include "croquette/types/user_types/CharacterScalarType.hpp"
#include "croquette/types/user_types/ComplexArrayType.hpp"

namespace Cqt = LibCqt;

int main(int argc, char** argv) {
    Cqt::init();
    CQT_STDOUT << std::boolalpha;

    Cqt::ComplexArrayType array;
    array.makeCellOfType<Cqt::FlatArrayType>();
    array.getAs<Cqt::FlatArrayType>(0)->makeCell(1);
    array.getAs<Cqt::FlatArrayType>(0)->makeCell(2);
    array.makeCell(3);
    array.makeCell(4);
    array.makeCellOfType<Cqt::ComplexArrayType>();
    array.getAs<Cqt::ComplexArrayType>(3)->makeCell(5);
    array.getAs<Cqt::ComplexArrayType>(3)->makeCellOfType<Cqt::FlatArrayType>();
    array.getAs<Cqt::ComplexArrayType>(3)->getAs<Cqt::FlatArrayType>(1)->makeCell(6);
    array.makeCellOfType<Cqt::CharacterScalarType>(55);
    CQT_STDOUT << array.asString();

    return 0;
}


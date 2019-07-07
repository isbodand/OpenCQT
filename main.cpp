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
#include <OptionsParser.hpp>
#include <versioning.hpp>
// Croquette STD
#include "croquette/cqt.hpp"
#include "croquette/types/user_types/FlatArrayType.hpp"
#include "croquette/types/user_types/ComplexArrayType.hpp"
#include "croquette/types/archetypes/ArchetypeUtilities.hpp"
#include "croquette/types/user_types/CharacterScalarType.hpp"
#include "croquette/types/user_types/HashmapType.hpp"
#include "croquette/types/user_types/OrderedMapType.hpp"
#include "croquette/versioning.hpp"
// OpenCQT
#include "versioning.hpp"
// LibStarch
#include "starch/versioning.hpp"

#include <boost/spirit/home/qi.hpp>

namespace Cqt = LibCqt;
namespace ip = InfoParse;
namespace ls = LibStarch;

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

void p(const char& c) {
    std::cout << c << std::endl;
}

int main(int argc, char** argv) {
    Cqt::init();

    bool help;

    ip::OptionsParser parser;
    parser.addOption("help", &help);

    auto files = parser.parse(argc, argv);

    if (help) {
        CQT_STDOUT << CQT_STRING("OpenCQT v") << OpenCqt::getVersion() << CQT_STRING(" built with: \n")
                   << CQT_STRING("CroquetteSTD v") << Cqt::getVersion() << CQT_STRING("\n")
                   << CQT_STRING("LibStarch v") << ls::getWVersion() << CQT_STRING("\n")
                   << CQT_STRING("InfoParse v") << ip::getVersion() << std::endl;
        return 0;
    }

    return 0;
}


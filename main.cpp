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

namespace Cqt = LibCroquette;

int main(int argc, char** argv) {
    Cqt::init();
    CQT_STDOUT << std::boolalpha;

    int cookieCount = 0;
    int cookieSweetness = 0;
    Cqt::String cookie;
    bool cocaine;
    bool meth;
    bool heisenberg;

    InfoParse::OptionsParser parser;
    parser.addOption("cookie-count", &cookieCount);
    parser.addOption("cookie-sweetness", 's', &cookieSweetness);
    parser.addOption("cookie", 'r', &cookie);
    parser.addOption("use-cocaine", 'H', &cocaine);
    parser.addOption("use-meth", 'm', &meth);
    parser.addOption("use-blue-meth", 'b', &heisenberg);

    auto retArgs = InfoParse::splitByWhitespace(parser.parse(argc, argv));

    CQT_STDOUT << CQT_STRING("Cookie: ") << cookie << std::endl
               << CQT_STRING("Use-Cocaine-In-Recipe: ") << cocaine << std::endl
               << CQT_STRING("Use-Meth: ") << meth << std::endl
               << CQT_STRING("Blue-Meth: ") << heisenberg << std::endl
               << CQT_STRING("Cookie-Count: ") << cookieCount << std::endl
               << CQT_STRING("Cookie-Sweetness: ") << cookieSweetness << std::endl
               << CQT_STRING("Remaining: #") << retArgs.size() << std::endl;

    return 0;
}


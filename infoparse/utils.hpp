//
// Created by bodand on 2019-01-20.
//

#ifndef OPENCQT_UNLESS_HPP
#define OPENCQT_UNLESS_HPP

#define unless(x) if (!(x))
#define until(x) while (!(x))

namespace InfoParse {
    std::string makeMonolithArgs(int argc, char** argv);
}

#endif //OPENCQT_UNLESS_HPP

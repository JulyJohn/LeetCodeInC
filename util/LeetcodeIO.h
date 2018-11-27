//
// Created by hejunhua on 18-11-23.
//

#ifndef LEETCODEINCPLUS_LEETCODEIO_H
#define LEETCODEINCPLUS_LEETCODEIO_H

#include <stdint.h>

#include <algorithm>
#include <fstream>  // NOLINT(readability/streams)
#include <string>
#include <vector>
#include <iostream>

namespace leetcode {
    using std::string;
    using std::vector;
    using std::ifstream;
    using std::ios;
    using std::stoi;

    bool readVectorFromTxt(const char *filename, vector<int> &vec);

    inline bool readVectorFromTxt(const string &filename, vector<int> &vec) {
        return readVectorFromTxt(filename.c_str(), vec);
    }
};


#endif //LEETCODEINCPLUS_LEETCODEIO_H

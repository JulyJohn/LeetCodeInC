//
// Created by hejunhua on 18-11-23.
//

#include "LeetcodeIO.h"

namespace leetcode {

    bool readVectorFromTxt(const char *filename, vector<int> &vec) {
        string tmp_line = "";
        ifstream readfile;
        readfile.open(filename, ios::in);
        if (readfile.fail()) {
            std::cout << "failed! check your input file path: " << filename << std::endl;
            return false;
        } else {
            while (getline(readfile, tmp_line)) {
                vec.push_back((int) stoi(tmp_line));
            }
        }
        return true;
    }


} // namespce leetcode
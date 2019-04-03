//
// Created by julyjohn on 2019-03-31.
//

/**
 *
 * 字符串中第一次出现的字符
 *
 * note：bitmap
 * */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 常规方法
    int FirstNotRepeatingChar(string str) {
        vector<short> bitmap(52, 0);
        int n = str.length();
        for (int i = 0; i < n; ++i) {
            short idx;
            if (str[i] >= 'a' && str[i] <= 'z') {
                idx = str[i] - 'a';
            } else {
                idx = str[i] - 'A' + 26;
            }
            bitmap[idx] += 1;
        }
        for (int i = 0; i < n; ++i) {
            short idx;
            if (str[i] >= 'a' && str[i] <= 'z') {
                idx = str[i] - 'a';
            } else {
                idx = str[i] - 'A' + 26;
            }
            if (bitmap[idx] == 1) {
                return i;
            }
        }
        return -1;
    }

    // 位运算
    int FirstNotRepeatingChar1(string str) {
        int *bitmap = new int[16]();
        int arr_idx, bit_idx;
        for (int i = 0; i < str.length(); ++i) {
            arr_idx = str[i] * 2 / 32;
            bit_idx = str[i] * 2 % 32;
            if (((bitmap[arr_idx] >> bit_idx) & 1) == 0) {
                bitmap[arr_idx] |= (1 << bit_idx);
            } else if (((bitmap[arr_idx] >> (bit_idx + 1)) & 1) == 0) {
                bitmap[arr_idx] |= (1 << (bit_idx + 1));
            }
        }
        for (int i = 0; i < str.length(); ++i) {
            arr_idx = str[i] * 2 / 32;
            bit_idx = str[i] * 2 % 32;
            if (((bitmap[arr_idx] >> bit_idx) & 1) == 1 && ((bitmap[arr_idx] >> (bit_idx + 1)) & 1) == 0) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution *solution = new Solution();
    string str = "google";
    cout << solution->FirstNotRepeatingChar(str);
    return 0;
}
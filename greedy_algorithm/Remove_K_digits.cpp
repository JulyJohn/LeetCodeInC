//
// Created by julyjohn on 2019-04-01.
//

/**
 *
 * 删除k个数字
 *
 * 题目描述：给定一个全为数字的字符串，删除其中的k个字符，使得剩下的字符串表示的数字最小。ps: 数字不能以0开头
 *
 * note: 贪心，尽可能地让小的数字出现在前面。
 * */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeKDigits(string str, int k) {
        string res = "";
        int new_len = str.size() - k;
        for (char c : str) {
            while (k > 0 && res.size() != 0 && c < res.back()) {
                --k;
                res.pop_back();
            }
            res.push_back(c);
        }
        res.resize(new_len);
        while (!res.empty() && res[0] == '0') {
            res.erase(res.begin());
        }
        return res.empty() ? "0" : res;
    }
};


int main() {
    Solution *solution = new Solution();
    cout << solution->removeKDigits("1432219", 3);
    return 0;
}
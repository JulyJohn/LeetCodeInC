//
// Created by yzjhh on 2019/3/28.
//

/**
 * 翻转单词顺序列
 *
 * note：例如，“student. a am I”，输出“I am a student.”。
 * */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        int n = str.length();
        vector<int> space_idx;
        int i = 0;
        while (i < n && str[i] == ' ') {
            ++i;
        }
        space_idx.emplace_back(i - 1);
        while (i < n) {
            if (str[i] == ' ') {
                space_idx.emplace_back(i);
            }
            i++;
        }
        for (int i = 1; i < space_idx.size(); ++i) {
            helper_reverse(str, space_idx[i - 1] + 1, space_idx[i] - 1);
            cout << str << endl;
        }
        helper_reverse(str, space_idx[space_idx.size() - 1] + 1, n - 1);
        cout << str << endl;
        helper_reverse(str, 0, n - 1);
        cout << str << endl;
        return str;
    }

    void helper_reverse(string &str, int start, int end) {
        while (start < end) {
            char tmp = str[start];
            str[start] = str[end];
            str[end] = tmp;
            ++start;
            --end;
        }
    }
};

int main() {
    Solution *solution = new Solution();
    string str = "student. a am I";
    solution->ReverseSentence(str);
    return 0;
}
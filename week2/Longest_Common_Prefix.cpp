//
// Created by yzjhh on 2019/1/24.
//

/**
 * 14. Longest Common Prefix

 Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 题目大意：
 找到一组字符串的最大相同前缀，如果没有共同前缀，就返回""


Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.

 * */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:

    string longestCommonPrefix(vector<string> &strs) {
        string res = "";
        for (int i = 0; i < strs[0].size(); ++i) {
            char cur_c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (cur_c != strs[j][i]) {
                    return res;
                }
            }
            res = res + cur_c;
        }
        return res;
    }
};

int main() {
//    vector<string> strs = {"flower", "flow", "flight"};
    vector<string> strs = {"dog","racecar","car"};

    Solution *solution = new Solution();
    cout << solution->longestCommonPrefix(strs);
    return 0;
}
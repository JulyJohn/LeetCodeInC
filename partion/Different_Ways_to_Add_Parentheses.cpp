//
// Created by yzjhh on 2019/3/7.
//

/**
 *
 * 241. Different Ways to Add Parentheses
 *
 * Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
 *
 * 题目描述：给出一个包含数字和运算操作符(+，-，*)的字符串，通过加上括号，返回可能的计算方式
 *

Example 1:

Input: "2-1-1"
Output: [0, 2]
Explanation:
((2-1)-1) = 0
(2-(1-1)) = 2
Example 2:

Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation:
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 分治 (优化可以考虑用一个map来存计算中间变量)
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int n = input.size();
        for (int i = 0; i < n; ++i) {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> res_l = diffWaysToCompute(input.substr(0, i)); // substr(pos, num)
                vector<int> res_r = diffWaysToCompute(input.substr(i + 1));
                for (int l = 0; l < res_l.size(); ++l) {
                    for (int r = 0; r < res_r.size(); ++r) {
                        if (c == '+') {
                            res.push_back(res_l[l] + res_r[r]);
                        } else if (c == '-') {
                            res.push_back(res_l[l] - res_r[r]);
                        } else {
                            res.push_back(res_l[l] * res_r[r]);
                        }
                    }
                }
            }
        }
        if (res.empty()) {
            res.push_back(atoi(input.c_str()));
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    string s = "2*3-4*5";
    vector<int > res = solution->diffWaysToCompute(s);
    return 0;
}
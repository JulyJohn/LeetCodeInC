//
// Created by yzjhh on 2019/1/19.
//

/**
 * 899. Orderly Queue

 A string S of lowercase letters is given.  Then, we may make any number of moves.

In each move, we choose one of the first K letters (starting from the left), remove it, and place it at the end of the string.

Return the lexicographically smallest string we could have after any number of moves.

 题目大意：给定一个小写字符串S，可以做任意次的移动。
 每次移动中，我们拿出从左至右的k个字符中的一个，放在字符串的末尾。
 返回字典顺序最小的字符串。

Example 1:

Input: S = "cba", K = 1
Output: "acb"
Explanation:
In the first move, we move the 1st character ("c") to the end, obtaining the string "bac".
In the second move, we move the 1st character ("b") to the end, obtaining the final result "acb".

Example 2:

Input: S = "baaca", K = 3
Output: "aaabc"
Explanation:
In the first move, we move the 1st character ("b") to the end, obtaining the string "aacab".
In the second move, we move the 3rd character ("c") to the end, obtaining the final result "aaabc".

Note:

1 <= K <= S.length <= 1000
S consists of lowercase letters only.
 * */
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string orderlyQueue(string S, int K) {
        // 当K>1的时候，相当于任意两个相邻的数都能交换，
        // 相当于整个字符串都可以重新排列
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        string res = S;
        for (int i = 1; i < S.length(); ++i) {
            string front_str = S.substr(0, i);
            string back_str = S.substr(i);
            res = min(res, back_str + front_str);
        }
        return res;
    }
};

int main() {
    Solution solution = Solution();
    string s = "cba";
    int K = 2;
    cout << solution.orderlyQueue(s, K);
    return 0;
}
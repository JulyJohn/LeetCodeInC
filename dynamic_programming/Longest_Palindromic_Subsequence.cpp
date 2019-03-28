//
// Created by yzjhh on 2019/3/28.
//

/**
 *
 * 516. Longest Palindromic Subsequence
 *
 * Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
 *
 * 题目描述：最长回文子序列（可以不连续），注意区分最长回文子串

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
 * */
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        // dp[i][j]表示起始位置为i，结尾位置为j的字符串中回文字串的最大长度
        // 有以下几种情况，
        //      1. 长度为1的字符串，肯定是回文，dp[i][i] = 1
        //      2. 对于任意子串
        //         2.1 如果首尾字符相等，那么它所包含的最大回文长度应该看把它首尾字符去掉后的字符串中所包含的最大回文长度
        //              dp[i][j] = dp[i+1][j-1]
        //             当然这种情况要求该子串长度大于2，如果等于2，那么它的最大长度就为2
        //         2.2 如果首尾不相等，那么就去掉首尾字符中的一个后再来看，取二者的较大值。
        vector<vector<int> > dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for (int l = 2; l <= n; ++l) {
            for (int start = 0; start + l - 1 < n; ++start) {
                int end = start + l - 1;
                if (s[end] == s[start]) {
                    dp[start][end] = l == 2 ? 2 : dp[start + 1][end - 1] + 2;
                } else {
                    dp[start][end] = max(dp[start][end - 1], dp[start + 1][end]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    Solution *solution = new Solution();
    string str = "cbbd";
    solution->longestPalindromeSubseq(str);
    return 0;
}
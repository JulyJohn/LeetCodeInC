//
// Created by yzjhh on 2019/3/17.
//

/**
 *
 * 91. Decode Ways
 *
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given a non-empty string containing only digits, determine the total number of ways to decode it.
 *
 * 题目描述：分割整数构成字母字符串，求所有可能的方式。
 *
 * note：令dp[i]为到第i个字符时的可能数量，那么存在两种情况：
             1.一个字符，那么就等于dp[i-1]
             2.两个字符，那么就再加上dp[i-2]
         要考虑的边界条件有：
             1. 一个字符的时候，不能为0
             2. 两个字符的时候，第一个字符不能为0，且组成的数字不能大于26

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 * */

class Solution {
public:
    // 令dp[i]为到第i个字符时的可能数量，那么存在两种情况：
    // 1.一个字符，那么就等于dp[i-1]
    // 2.两个字符，那么就再加上dp[i-2]
    // 要考虑的边界条件有：
    // 1. 一个字符的时候，不能为0
    // 2. 两个字符的时候，不能大于26
    int numDecodings(string s) {
        int n = s.length();
        vector<int > dp(n+1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for(int i = 2; i <= n; ++i){
            // 先考虑一个字符的情况
            if(s[i-1] != '0'){ // 等于0的话就只有可能是跟上一个字符组成一个数字了，例如10,20
                dp[i] = dp[i-1];
            }
            // 现在考虑两个字符的情况
            if(s[i-2] == '0'){
                continue;
            }
            if(atoi(s.substr(i-2,2).c_str()) < 27){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};
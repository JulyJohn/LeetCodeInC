//
// Created by yzjhh on 2019/3/9.
//

/**
 *
 * 343. Integer Break
 *
 * Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
 *
 * 题目描述：一个正数可以拆分成至少两个数的和，求这些数的最大乘积。

Example 1:

Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
Note: You may assume that n is not less than 2 and not larger than 58.
 * */

class Solution {
public:
    int integerBreak(int n) {
        vector<int > dp(n+1);
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <= i/2; ++j){ // 例如：9=1+8=2+7=3+6=4+5，所以是1~i/2
                dp[i] = max(dp[i], max(j, dp[j]) * max(i-j, dp[i-j]));
            }
        }
        return dp[n];
    }
};
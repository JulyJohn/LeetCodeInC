//
// Created by yzjhh on 2019/3/17.
//

/**
 *
 * 279. Perfect Squares
 *
 * Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * 题目描述：找到一个数可以由完美平方数
 *
 * note：如果一个数x可以表示为一个任意数a加上一个平方数bｘb，也就是x=a+bｘb，那么能组成这个数x最少的平方数个数，就是能组成a最少的平方数个数加上1（因为b*b已经是平方数了）。

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 *
 * */

class Solution {
public:
    // 任何一个数可以表示为a + b * b, 那么就可能有两种情况，一种是这个数本来就是一个平方数，另一种就是a的完美平方数加上b*b这种情况，因此是dp[a]+1，取二者的较小值。
    int numSquares(int n) {
        vector<int > dp(n + 1, INT32_MAX);
        for(int i = 1; i * i <= n; ++i){
            dp[i * i] = 1;
        }
        for(int a = 1; a <= n; ++a){
            for(int b = 1; a + b * b <= n; ++b){
                dp[a + b * b] = min(dp[a] + 1, dp[a + b * b]);
            }
        }
        return dp[n];
    }
};
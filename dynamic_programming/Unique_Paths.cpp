//
// Created by yzjhh on 2019/3/17.
//

/**
 * 62. Unique Paths
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 *
 * 题目描述：求矩阵左上角到右下角的总路径数
 *
 * note：二维dp到一维dp的优化
 *
 * Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
 *
 * */

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 一维dp
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];

//        二维dp
//        vector<vector<int >> dp(m, vector<int >(n, 1));
//        if(m < 1 || n < 1){
//            return 0;
//        }
//        for(int i = 1; i < m; ++i){
//            for(int j = 1; j < n; ++j){
//                dp[i][j] = dp[i-1][j] + dp[i][j-1];
//            }
//        }
//        return dp[m-1][n-1];
    }
};
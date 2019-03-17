//
// Created by yzjhh on 2019/3/17.
//

/**
 *
 * 64. Minimum Path Sum
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 *
 * note: 矩阵的最小路径和
 *
Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 *
 * */

class Solution {
public:

    // 一维dp改进
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n;
        if(m < 1){
            return 0;
        }else{
            n = grid[0].size();
            if(n < 1){
                return 0;
            }
        }
        vector<int > dp(n, 0);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(j == 0){
                    dp[j] = grid[i][j] + dp[j];
                }else if(i == 0){
                    dp[j] = grid[i][j] + dp[j-1];
                }else{
                    dp[j] = grid[i][j] + min(dp[j-1], dp[j]);
                }
            }
        }
        return dp[n-1];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m;
        if(n < 1){
            return 0;
        }else{
            m = grid[0].size();
            if(m < 1){
                return 0;
            }
        }
        for(int i = 1; i < n; ++i){
            grid[i][0] += grid[i-1][0];
        }
        for(int i = 1; i < m; ++i){
            grid[0][i] += grid[0][i-1];
        }
        for(int i = 1; i < n; ++i){
            for(int j = 1; j < m; ++j){
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[n-1][m-1];
    }
};
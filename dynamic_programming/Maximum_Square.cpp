//
// Created by yzjhh on 2019/4/9.
//

/**
 *
 * 221. Maximal Square
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
 *
 * 题目描述：给一个元素都是0和1的二维数组，找出其中由1组成的最大正方形面积。

Example:

Input:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
 * */

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0){
            return 0;
        }
        int n = matrix[0].size();
        int max_len = 0;
        // 1D dp，参考矩阵路径的dp优化,用一个pre变量来记录dp[i-1][j-1]
        int pre, tmp;
        vector<int> dp(n+1, 0);
        for(int i = 0; i < m; ++i){
            for(int j = 1; j <= n; ++j){
                tmp = dp[j];
                if(i == 0){
                    dp[j] = matrix[i][j-1] == '1' ? 1 : 0;
                }else{
                    dp[j] = matrix[i][j-1] == '1' ? min(pre, min(dp[j], dp[j-1])) + 1 : 0;
                }
                max_len = max(max_len, dp[j]);
                pre = tmp;
            }
        }
        /* 2D dp
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i == 0 || j == 0){
                    dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
                    max_len = max(max_len, dp[i][j]);
                    continue;
                }
                dp[i][j] = matrix[i][j] == '1' ? min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1 : 0;
                max_len = max(max_len, dp[i][j]);
            }
        }
        */

        return max_len * max_len;
    }
};
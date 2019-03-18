//
// Created by yzjhh on 2019/3/18.
//

/**
 *
 * 48. Rotate Image
 *
 * 题目描述：将一个矩阵旋转90度
 *
 * */

class Solution {
public:
    // 每个数字的移动都牵扯到四个数，并且四个数环环相扣，（类似于挖坑填萝卜）
    // 有如下的关系：
    // matrix[i][j] = matrix[n-1-j][i];
    // matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
    // matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
    // matrix[j][n-1-i] = matrix[i][j];
    // 边界条件为
    // 1. i <= (n-1)/2
    // 2. j < n-1-i
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int tmp = 0;
        int end_i = (n-1)/2;
        for(int i = 0; i <= end_i; ++i){
            for(int j = i; j < n-1-i; ++j){
                tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }
    }
};
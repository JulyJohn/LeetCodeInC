//
// Created by yzjhh on 2019/3/27.
//

/**
 *
 * 最大子矩阵
 *
 * 题目描述：
 * 已知矩阵的大小定义为矩阵中所有元素的和。
 * 给定一个矩阵，你的任务是找到最大的非空(大小至少是1 * 1)子矩阵。
 * 比如，如下4 * 4的矩阵 0 -2 -7 0 9 2 -6 2 -4 1 -4 1 -1 8 0 -2 的最大子矩阵是 9 2 -4 1 -1 8 这个子矩阵的大小是15。
 *
 * note：对于任意一个矩阵，将其列上的元素相加即可压缩成一行，从而转换为一维数组的最大子序列和问题
 * */


#include<iostream>
#include<vector>

using namespace std;

int maxSubArraySum(vector<int > arr){
    int n = arr.size();
    if(n == 0){
        return 0;
    }
    int preSum = arr[0];
    int maxSum = preSum;
    for(int i = 1; i < n; ++i){
        preSum = preSum > 0 ? preSum + arr[i] : arr[i];
        maxSum = max(maxSum, preSum);
    }
    return maxSum;
}

int main(){
    int n;
    int tmp_maxSum;
    int maxSum = INT32_MIN;
    while(scanf("%d", &n) != EOF){
        vector<vector<int > > matrix(n, vector<int >(n, 0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                scanf("%d", &matrix[i][j]);
            }
        }
        vector<int > line(n, 0);
        for(int i = 0; i < n; ++i){ // 起始行
            for(int j = i; j < n; ++j){ // 终止行
                for(int k = 0; k < n; ++k){ // 统计列上面的和
                    line[k] += matrix[j][k];
                }
                tmp_maxSum = maxSubArraySum(line);
                maxSum = max(maxSum, tmp_maxSum);
            }
            line.assign(n, 0);
        }
        cout << maxSum << endl;
    }
    return 0;
}

//
// Created by yzjhh on 2019/4/3.
//

/**
 *
 * n个骰子的点数
 *
 * 题目描述：把 n 个骰子仍在地上，求点数和为 s 的概率。
 *
 * */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        // Write your code here
        // dp[i][j]，i表示第i次投掷，j表示总共投了多大的点数
        vector<vector<long> > dp(n+1, vector<long >(n*6+1, 0));

        // 初始化，第一次可能投出来的点数有6种
        for (int i = 1; i <= 6; i++) {
            dp[1][i] = 1;
        }

        // 更新公式
        // dp[i][j] = dp[i-1][j-k] 1<=k<=6 && k < j
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= 6*n; j++) {
                for (int k = 1; k <=6 && k < j; k++) {
                    dp[i][j] += dp[i-1][j-k];
                }
            }
        }

        // 计算概率
        double totalNums = pow(6, n);
        vector<pair<int, double> > res(6*n-n+1);
        for (int i = n; i <= 6*n; i++) {
            res[i-n] = {i, dp[n][i]/totalNums};
        }
        return res;
    }
};


int main(){
    Solution *solution = new Solution();
    solution->dicesSum(14);
    return 0;
}
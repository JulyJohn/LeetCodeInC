//
// Created by yzjhh on 2019/3/8.
//

/**
 *
 * 97. Interleaving String
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 * 题目描述：判断s3是否由s1和s2交错组成。
 *
 * note：dp问题，画状态图，总结状态转移方程，以及初始化条件。
 *
 * */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n3 = s3.length();
        int n2 = s2.length();
        int n1 = s1.length();
        if((n1 + n2) != n3){
            return false;
        }

        vector<vector<bool > > dp(n1 + 1, vector<bool> (n2 + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n1; ++i){
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        }
        for(int j = 1; j <= n2; ++j){
            dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
        }

        for(int i = 1; i <= n1; ++i){
            for(int j = 1; j <= n2; ++j){
                dp[i][j] = (dp[i-1][j] && (s3[i+j-1] == s1[i-1])) || (dp[i][j-1] && (s3[i+j-1] == s2[j-1]));
            }
        }

        return dp[n1][n2];
    }
};

int main() {
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";

    Solution *solution = new Solution();
    solution->isInterleave(s1, s2, s3);
    return 0;
}
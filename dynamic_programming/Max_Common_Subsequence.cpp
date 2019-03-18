//
// Created by yzjhh on 2019/3/18.
//

/**
 *
 * 最长公共子串，不要求连续
 *
 * */

int maxCommonSubsequence(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    if(m == 0 || n == 0){
        return 0;
    }
    vector<vector<int >> dp(m+1, vector<int >(n+1, 0));
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
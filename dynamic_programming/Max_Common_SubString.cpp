//
// Created by yzjhh on 2019/3/14.
//

/**
 *
 * 最长公共子序列
 *
 * note:
 *
 * dp[i][j] = dp[i-1][j-1] + 1, str1[i] == str[j]
 * dp[i][j] = 0, str1[i] != str[j]
 *
 * */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCommonSubstring(string str1, string str2) {
        int n1 = str1.length() + 1;
        int n2 = str2.length() + 1;
        vector<vector<int >> dp(n1, vector<int>(n2, 0));

        int max_len = 0;
        int idx = 0;
        int i = 0;
        while (++i < n1) {
            for (int j = 1; j < n2; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] > max_len) {
                        max_len = dp[i][j];
                        idx = i;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        cout << "idx: " << idx - 1 << " max_len: " << max_len << endl;
    }

};

int main() {
    Solution *solution = new Solution();
    solution->maxCommonSubstring("acbcbcef", "abcbced");
    return 0;
}
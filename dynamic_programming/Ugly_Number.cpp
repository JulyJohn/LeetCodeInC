//
// Created by yzjhh on 2019/4/10.
//

/**
 * 
 * 丑数
 *
 * 题目描述：把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int n) {
        if (n <= 6) {
            return n;
        }
        int idx_2 = 0; // 因数包含2的位置
        int idx_3 = 0; // 因数包含3的位置
        int idx_5 = 0; // 因数包含5的位置
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            // 看包含哪个因数的位置上的值最小，同时更新这个最小值所在的位置
            dp[i] = min(dp[idx_2] * 2, min(dp[idx_3] * 3, dp[idx_5] * 5));
            if (dp[i] == dp[idx_2] * 2) {
                ++idx_2;
            }
            if (dp[i] == dp[idx_3] * 3) {
                ++idx_3;
            }
            if (dp[i] == dp[idx_5] * 5) {
                ++idx_5;
            }
        }
        return dp[n - 1];
    }
};

int main() {
    Solution *solution = new Solution();
    solution->GetUglyNumber_Solution(7);
    return 0;
}
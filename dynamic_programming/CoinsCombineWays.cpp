//
// Created by yzjhh on 2019/8/31.
//

/**
 *
 * 硬币表示
 *
 * 有数量不限的硬币，币值为25分、10分、5分和1分，请编写代码计算n分有几种表示法。
 *
 * 给定一个int n，请返回n分有几种表示法。保证n小于等于100000，为了防止溢出，请将答案Mod 1000000007。
 *
 * 测试样例：6
 * 返回：2
 * */

class Coins {
public:
    int countWays(int n) {
        // write code here
        vector<int> dp(n+1, 1);
        vector<int> coin = {1, 5, 10, 25};
        dp[0] = 1;
        for(int i = 1; i < 4; ++i){
            for(int j = coin[i]; j <= n; ++j){
                // dp[j]表示最后一个硬币不为coin[i]；
                // dp[j - coin[i]]表示最后一个硬币为coin[i]；
                dp[j] = (dp[j] + dp[j - coin[i]]) % 1000000007;
            }
        }
        return dp[n];
    }
};
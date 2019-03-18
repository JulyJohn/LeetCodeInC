//
// Created by yzjhh on 2019/3/18.
//

/**
 *
 * 188. Best Time to Buy and Sell Stock IV
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most k transactions.
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 *
 * 题目描述：股票问题4，k次交易所能达到的最大利润。
 *
 * note: 注意 k>=n/2的情况，此时应该按照普通方法处理，买一次卖一次这样。

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 * */


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || k == 0){
            return 0;
        }
        if(k >= n/2){
            int maxProfit = 0;
            int diff = 0;
            for(int i = 1; i < n; ++i){
                diff = prices[i] - prices[i-1];
                if(diff > 0){
                    maxProfit += diff;
                }
            }
            return maxProfit;
        }

        vector<int > buy(k, INT32_MIN);
        vector<int > sell(k, 0);
        for(int i = 0; i < n; ++i){
            buy[0] = max(buy[0], -prices[i]);
            sell[0] = max(sell[0], buy[0] + prices[i]);
            for(int j = 1; j < k; ++j){
                buy[j] = max(buy[j], sell[j-1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k-1];
    }
};
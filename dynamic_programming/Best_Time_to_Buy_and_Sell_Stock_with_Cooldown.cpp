//
// Created by yzjhh on 2019/3/17.
//

/**
 *
 * 309. Best Time to Buy and Sell Stock with Cooldown
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 *
 * 问题描述：股票交易之存在一天的冷却期，即刚卖出后要等待一天才能再买入。
 *
 * 有四个状态：
 * 1. 买入状态
 * 2. 买入后的冷却状态
 * 3. 卖出状态
 * 4. 卖出后的冷却状态
 *
 * 画出状态转移图，列出公式即可
 *
Example:

Input: [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
 * */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0){
            return 0;
        }
        int pre_buy = 0;
        int pre_sell = 0;
        int buy = INT32_MIN;
        int sell = 0;
        for(int i = 0; i < n; ++i){
            pre_buy = buy;
            buy = max(pre_sell - prices[i], pre_buy);
            pre_sell = sell;
            sell = max(pre_buy + prices[i], pre_sell);
        }
        return sell;
//        vector<int > buy(n);
//        vector<int > sell(n);
//        vector<int > s1(n);
//        vector<int > s2(n);
//        buy[0] = -prices[0];
//        s1[0] = buy[0];
//        sell[0] = 0;
//        s2[0] = 0;
//        for(int i = 1; i < n; ++i){
//            buy[i] = s2[i-1] - prices[i];
//            s1[i] = max(buy[i-1], s1[i-1]);
//            sell[i] = max(buy[i - 1], s1[i - 1]) + prices[i];
//            s2[i] = max(s2[i-1], sell[i-1]);
//        }
//        return max(sell[n-1], s2[n-1]);
    }
};
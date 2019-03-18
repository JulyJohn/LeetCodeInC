//
// Created by yzjhh on 2019/3/18.
//

/**
 *
 * 122. Best Time to Buy and Sell Stock II
 *
 * 题目描述：股票问题2，交易次数没有限制。
 *
 * Note：对于 [a, b, c, d]，如果有 a <= b <= c <= d ，那么最大收益为 d - a。而 d - a = (d - c) + (c - b) + (b - a) ，
 * 因此当访问到一个 prices[i] 且 prices[i] - prices[i-1] > 0，那么就把 prices[i] - prices[i-1] 添加到收益中，从而在局部最优的情况下也保证全局最优。
 *
 * */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        for(int i = 1; i < n; ++i){
            int diff = prices[i] - prices[i-1];
            if(diff > 0){
                max_profit += diff;
            }
        }
        return max_profit;
    }
};
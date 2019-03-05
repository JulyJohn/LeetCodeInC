//
// Created by yzjhh on 2019/3/5.
//
/**
 *
 * 739. Daily Temperatures
 *
 * Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature.
 * If there is no future day for which this is possible, put 0 instead.
 *
 * 题目描述：数组中元素与下一个比它大的元素之间的距离
 *

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
 *
 * */
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        stack<int > s;
        vector<int > res(n, 0);
        int pre_idx;
        for(int i = 0; i < n; ++i){
            while(!s.empty() && T[i] > T[s.top()]){
                pre_idx = s.top();
                s.pop();
                res[pre_idx] = i - pre_idx;
            }
            s.push(i);
        }
        return res;
    }
};
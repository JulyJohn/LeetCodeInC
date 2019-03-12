//
// Created by yzjhh on 2019/3/12.
//

/**
 *
 * 题目 : 求数组中两个元素差的最大值
 * 求数组中两个元素差的最大值（后面的元素减去前面的元素）；对应实际生活中的股票买卖，找出可能的最大收益；
 *
 * note：动态规划
 *
 * 一方面要记录最大值，同时要记录下最小值，因为减数越小，那么最后的差值也就越大
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int max_difference(vector<int> arr) {
        int n = arr.size();
        if (n < 2) {
            return 0;
        }
        int max_diff = abs(arr[1] - arr[0]);
        int min_val = min(arr[0], arr[1]);

        for (int i = 2; i < n; ++i) {
            if (arr[i] - min_val > max_diff) {
                max_diff = arr[i] - min_val;
            } else if (arr[i] < min_val) {
                min_val = arr[i];
            }
        }
        return max_diff;
    }
};


int main() {
    return 0;
}
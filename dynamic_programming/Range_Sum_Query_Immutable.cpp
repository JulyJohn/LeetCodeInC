//
// Created by yzjhh on 2019/3/17.
//

/**
 *
 * 303. Range Sum Query - Immutable
 * 数组区间和。
 *
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 *
 * 题目描述：求区间 i ~ j 的和，可以转换为 sum[j + 1] - sum[i]，其中 sum[i] 为 0 ~ i - 1 的和。
 *

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
 *
 * */

class NumArray {
private:
    vector<int > dp;
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        dp.resize(n+1);
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i-1] + nums[i-1];
        }
    }

    int sumRange(int i, int j) {
        return dp[j+1] - dp[i];
    }
};
//
// Created by yzjhh on 2019/3/1.
//

/**
 *
 * 最大子数组差
 *
 * note:参考最大子数组和的解法，用两个数组记录到i的左边最大子数组和与右边最小子数组和，然后遍历两个数组左边减右边，求最大值；然后反转数组，再来一次，求两次最大值的最大值。
 *
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two substrings
     */
    int maxDiffSubArrays(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        int diff1 = helper(nums, n);
        reverse(nums.begin(), nums.end());
        int diff2 = helper(nums, n);
        return max(diff1, diff2);
    }

    int helper(vector<int> &nums, int n) {
        int pre_sum_max = INT32_MIN;
        int max_sum = pre_sum_max;
        int pre_sum_min = INT32_MAX;
        int min_sum = pre_sum_min;
        vector<int> leftMax(n, 0);
        vector<int> rightMin(n, 0);
        for (int i = 0; i < n; ++i) {
            pre_sum_max = pre_sum_max < 0 ? nums[i] : pre_sum_max + nums[i];
            pre_sum_min = pre_sum_min > 0 ? nums[n - 1 - i] : pre_sum_min + nums[n - 1 - i];
            max_sum = max(max_sum, pre_sum_max);
            min_sum = min(min_sum, pre_sum_min);
            leftMax[i] = max_sum;
            rightMin[n - 1 - i] = min_sum;
        }
        int max_diff = 0;
        for (int i = 1; i < n; ++i) {
            max_diff = max(max_diff, abs(leftMax[i - 1] - rightMin[i]));
        }
        return max_diff;
    }
};

int main(){
    Solution *solution = new Solution();
    vector<int > nums = {-4, -5};
    solution->maxDiffSubArrays(nums);
    string s = "";
    return 0;
}
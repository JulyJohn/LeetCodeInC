//
// Created by yzjhh on 2019/3/18.
//

/**
 *
 * 53. Maximum Subarray
 *
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 *
 * 题目描述：找到数组中连续子序列的最大和
 *
 * note：要求和最大，如果前面的sum小于0的话，那么这个sum对最终的结果只会产生负的影响，因此可以丢弃，重新计算sum

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
 * */


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n < 1){
            return 0;
        }
        // 要求和最大，如果前面的sum小于0的话，那么这个sum对最终的结果只会产生负的影响，因此可以丢弃，重新计算sum
        int pre_sum = nums[0];
        int max_sum = pre_sum;
        for(int i = 1; i < n; ++i){
            pre_sum = pre_sum > 0 ? pre_sum + nums[i] : nums[i];
            max_sum = pre_sum > max_sum ? pre_sum : max_sum;
        }
        return max_sum;
    }
};
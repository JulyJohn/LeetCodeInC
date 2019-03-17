//
// Created by yzjhh on 2019/3/17.
//

/**
 *
 * 213. House Robber II
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 *
 * note：分两种情况，第一个节点被偷了，那么最后一个节点就不能被偷；反之成立。

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
 * */


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }else if(n == 1){
            return nums[0];
        }
        vector<int > dp(n+1);
        dp[0] = 0;
        // robbed
        dp[1] = nums[0];
        for(int i = 2; i < n; ++i){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        int val_robbed = max(dp[n-1], dp[n-2]);
        dp[1] = 0;
        for(int i = 2; i < n; ++i){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        int val_not_robbed = max(dp[n-1], dp[n-2] + nums[n-1]);
        return max(val_not_robbed, val_robbed);
    }
};
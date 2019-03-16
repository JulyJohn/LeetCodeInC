//
// Created by yzjhh on 2019/3/16.
//

/**
 *
 * 376. Wiggle Subsequence
 *
 * 题目描述：找出满足同时大于或小于两边相邻的数的最长子序列，即a[i-1] < a[i] > a[i+1] 或a[i-1] > a[i] < a[i+1]
 *
 * */

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return n;
        }
        int up = 1;
        int down = 1;
        for(int i = 1; i < n; ++i){
            if(nums[i] == nums[i-1]){
                continue;
            }else if(nums[i] > nums[i-1]){
                up = down + 1;
            }else{
                down = up + 1;
            }
        }
        return max(up, down);
    }
};
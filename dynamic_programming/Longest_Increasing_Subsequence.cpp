//
// Created by yzjhh on 2019/3/15.
//

/**
 *
 * 300. Longest Increasing Subsequence
 *
 * Given an unsorted array of integers, find the length of longest increasing subsequence.
 *
 * 题目描述：给出一个未排序的整型数组，找出最大递增子序列的长度。
 *

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findFirtGreaterIndex(vector<int > nums, int len, int target){
        int lo = 0;
        int hi = len - 1;
        int mid;
        while(lo <= hi){
            mid = lo + (hi - lo) / 2;
            if(nums[mid] < target){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        return lo;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return n;
        }
        vector<int > lis(n);
        lis.push_back(nums[0]);
        int len = 0;
        for(int i = 0; i < n; ++i){
            int idx = findFirtGreaterIndex(lis, len, nums[i]);
            lis[idx] = nums[i];
            if(idx == len){
                ++len;
            }
        }
        return len;
    }

//    int lengthOfLIS(vector<int>& nums) {
//        int n = nums.size();
//        if(n < 2){
//            return n;
//        }
//        vector<int> dp(n,1);
//        for(int i = 1; i < n; ++i){
//            for(int j = i - 1; j >= 0; --j){
//                if(nums[j] < nums[i]){
//                    dp[i] = max(dp[i], dp[j] + 1);
//                }
//            }
//        }
//        int max_len = 1;
//        for(int i = 0; i < n; ++i){
//            if(dp[i] > max_len){
//                max_len = dp[i];
//            }
//        }
//        return max_len;
//    }
};


int main(){
    Solution *solution = new Solution();
    vector<int > nums = {10,9,2,5,3,7,101,18};
    solution->lengthOfLIS(nums);
    return 0;
}
//
// Created by yzjhh on 2019/3/27.
//

/**
 *
 * 15. 3Sum
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * 题目描述：从数组中找出三个数，使之相加的和为0
 *
 * note：
 * 1. 固定一个数，转换成2sum问题
 * 2. 注意去除重复的情况

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 * */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 3){
            return res;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i){
            if(nums[i] > 0){
                break;
            }
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int target = -nums[i];
            int l = i + 1;
            int r = n - 1;
            while(l < r){
                int tmp_sum = nums[l] + nums[r];
                if(tmp_sum == target){
                    vector<int > triple = {nums[i], nums[l], nums[r]};
                    res.emplace_back(triple);
                    ++l;
                    --r;
                    while(l < r && nums[l] == nums[l-1]){
                        ++l;
                    }
                    while(l < r && nums[r] == nums[r+1]){
                        --r;
                    }
                }else if(tmp_sum < target){
                    ++l;
                }else{
                    --r;
                }
            }
        }
        return res;
    }
//    vector<vector<int>> threeSum(vector<int> &nums) {
//        vector<vector<int>> res;
//        sort(nums.begin(), nums.end());
//        if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
//        for (int k = 0; k < nums.size(); ++k) {
//            if (nums[k] > 0) break;
//            if (k > 0 && nums[k] == nums[k - 1]) continue;
//            int target = 0 - nums[k];
//            int i = k + 1, j = nums.size() - 1;
//            while (i < j) {
//                if (nums[i] + nums[j] == target) {
//                    res.push_back({nums[k], nums[i], nums[j]});
//                    while (i < j && nums[i] == nums[i + 1]) ++i;
//                    while (i < j && nums[j] == nums[j - 1]) --j;
//                    ++i;
//                    --j;
//                } else if (nums[i] + nums[j] < target) ++i;
//                else --j;
//            }
//        }
//        return res;
//    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution *solution = new Solution();
    solution->threeSum(nums);
    return 0;
}
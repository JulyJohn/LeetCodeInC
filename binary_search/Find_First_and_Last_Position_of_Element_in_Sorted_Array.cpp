//
// Created by yzjhh on 2019/3/6.
//

/**
 *
 * 34. Find First and Last Position of Element in Sorted Array
 *
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 *
 * 题目描述：在已排序数组中找到一个重复数字所在的区间。
 *

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
 * */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int > interval(2, -1);
        int start = findFirstIdx(nums, target - 1);
        if(start < n && nums[start] == target){
            int end = findFirstIdx(nums, target) - 1;
            interval[0] = start;
            interval[1] = end;
        }
        return interval;
    }

    // 查找大于给定元素的第一个元素的位置
    int findFirstIdx(vector<int>& nums, int target){
        int lo = 0;
        int hi = nums.size() - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(target >= nums[mid]){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        return lo;
    }
};
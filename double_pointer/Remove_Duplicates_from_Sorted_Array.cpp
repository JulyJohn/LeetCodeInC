//
// Created by yzjhh on 2019/3/12.
//

/**
 *
 * 26. Remove Duplicates from Sorted Array
 *
 * 题目描述：移除排序数组中的重复元素
 *
 * */

class Solution {
public:

    /**
     *
     * 用两个指针，快指针往前遍历，慢指针记录不重复的元素
     *
     * */
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return n;
        }
        int slow = 0;
        int fast = 0;
        while(fast < n){
            if(nums[slow] != nums[fast]){
                nums[++slow] = nums[fast];
            }
            ++fast;
        }
        return slow+1;
    }
};
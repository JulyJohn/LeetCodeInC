//
// Created by yzjhh on 2019/3/18.
//

/**
 *
 * 152. Maximum Product Subarray
 *
 * Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
 *
 * 题目描述：找到数组中连续子序列的最大积

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 *
 * */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int pre_product_min = nums[0];
        int pre_product_max = nums[0];
        int max_product = nums[0];
        for(int i = 1; i < n; ++i){
            int tmp_min = min(min(pre_product_min*nums[i], pre_product_max*nums[i]), nums[i]);
            int tmp_max = max(max(pre_product_min*nums[i], pre_product_max*nums[i]), nums[i]);
            pre_product_min = tmp_min;
            pre_product_max = tmp_max;
            max_product = max(pre_product_max, max_product);
        }
        return max_product;
    }
};
//
// Created by yzjhh on 2019/2/23.
//

/**
 * 75. Sort Colors
 *
 * Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 *
 * 題目大意：有三种颜色的球，算法的目标是将这三种球按颜色顺序正确地排列。

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?

 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int lt = 0;
        int i = 0;
        int gt = nums.size() - 1;
        int base = 1;
        while (i <= gt) {
            if (nums[i] == 0) {
                nums[i++] = nums[lt];
                nums[lt++] = 0;
            } else if (nums[i] == 2) {
                nums[i] = nums[gt];
                nums[gt--] = 2;
            } else {
                ++i;
            }
        }
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    solution->sortColors(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ", ";
    }
}
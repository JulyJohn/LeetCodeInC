//
// Created by yzjhh on 2019/2/4.
//

/**
 * 167. Two Sum II - Input array is sorted

 Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

 给出一个按递增顺序排序好的整数数组，从中找出相加起来正好等于给定数值的两个数字，返回这两个数字在数组中的位置（从1开始技术）。

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 * */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int index1 = 1;
        int index2 = numbers.size();
        vector<int> ans;
        while (index1 < index2) {
            int sum = numbers[index1 - 1] + numbers[index2 - 1];
            if (sum > target) {
                index2--;
            } else if (sum < target) {
                index1++;
            } else {
                ans.push_back(index1);
                ans.push_back(index2);
                return ans;
            }
        }
        return ans;
    }
};


int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    Solution *solution = new Solution();
    vector<int> ans = solution->twoSum(numbers, target);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }

}
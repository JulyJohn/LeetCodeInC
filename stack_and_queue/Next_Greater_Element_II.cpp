//
// Created by yzjhh on 2019/3/5.
//

/**
 * 503. Next Greater Element II
 *
 * Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element.
 * The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number.
 * If it doesn't exist, output -1 for this number.
 *
 * 题目描述：循环数组中比当前元素大的下一个元素
 *

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number;
The second 1's next greater number needs to search circularly, which is also 2.
 *
 * */
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> res(n, -1);
        for (int i = 0; i < n * 2; ++i) {
            int cur_num = nums[i % n];
            while (!s.empty() && nums[s.top()] < cur_num) {
                int idx = s.top();
                s.pop();
                res[idx] = cur_num;
            }
            if (i < n) {
                s.push(i);
            }
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> nums = {1, 2, 1};
    solution->nextGreaterElements(nums);
    return 0;
}
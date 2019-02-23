//
// Created by yzjhh on 2019/2/23.
//

/**
 *
 * 347. Top K Frequent Elements
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * 题目大意： 给出一个非空的数组，返回出现频率最高的前k个元素
 *

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 * */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    vector<int> topKFrequent(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int, int> nums_frequecy;
        for (int i = 0; i < n; ++i) {
            if (nums_frequecy.find(nums[i]) == nums_frequecy.end()) {
                nums_frequecy.emplace(nums[i], 1);
            } else {
                nums_frequecy[nums[i]] = nums_frequecy[nums[i]] + 1;
            }
        }

        vector<vector<int >> bucket(n + 1);
        unordered_map<int, int>::iterator it;
        for (it = nums_frequecy.begin(); it != nums_frequecy.end(); it++) {
            bucket[it->second].push_back(it->first);
        }

        vector<int> res = {};
        int k_cnt = 0;
        for (int i = n; i >= 0; --i) {
            if (bucket[i].size() != 0) {
                for (int j = 0; j < bucket[i].size(); ++j) {
                    k_cnt++;
                    res.push_back(bucket[i][j]);
                }
                if (k_cnt == k) {
                    return res;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> nums = {1};
    int k = 1;

    vector<int> res = solution->topKFrequent(nums, k);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << ", ";
    }
}
//
// Created by julyjohn on 2019-04-01.
//

/**
 *
 * 找到第k大的元素在原数组中的位置
 *
 * 题目描述： float类型，o(1)空间，不能改变原数组
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<float > &nums, int k) {
        int n = nums.size();
        if (n == 0 || k > n) {
            return -1;
        }
        int max_idx = 0;
        int min_idx = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[max_idx] < nums[i]) {
                max_idx = i;
            }
            if (nums[min_idx] > nums[i]) {
                min_idx = i;
            }
        }
        float max_val = nums[max_idx];
        float min_val = nums[min_idx];
        int idx1 = 0; // 数组中大于等于mid的数中最小的那个数的位置
        int idx2; // 数组中大于mid的数中最小的那个数的位置
        while (min_val <= max_val) {
            float mid = min_val + (max_val - min_val) / 2.;
            int cnt1 = 0; // 数组中大于等于mid的数的个数
            int cnt2 = 0; // 数组中大于mid的数的个数
            idx1 = max_idx;
            idx2 = max_idx;
            for (int i = 0; i < n; ++i) {
                if (nums[i] >= mid) {
                    ++cnt1;
                    if (nums[idx1] >= nums[i]) {
                        idx1 = i;
                    }
                }
                if (nums[i] > mid) {
                    ++cnt2;
                    if (nums[idx2] > nums[i]) {
                        idx2 = i;
                    }
                }
            }
            if (cnt1 >= k && cnt2 < k) { // 大于等于mid的数的个数大于等于k（可能有重复的数），比mid大的数的个数小于k
                break;
            } else if (cnt1 < k) {
                max_val = mid;
            } else {
                min_val = nums[idx2]; // 不能直接赋值为mid，防止进入死循环
            }
        }
        return idx1;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<float > nums = {1, 2, 3, 4, 5, 6};
    int k = 1;
    int idx = solution->findKthLargest(nums, k);
    cout << nums[idx];
    return 0;
}
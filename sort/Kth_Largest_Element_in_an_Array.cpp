//
// Created by yzjhh on 2019/2/21.
//

/**
 * 215. Kth Largest Element in an Array
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 *
 * 题目大意： 从一个乱序得数组中找到第k大的元素。
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
        快速排序
    */
    int partion(vector<int> &nums, int lo, int hi) {
        int i = lo;
        int j = hi;
        int curVal = nums[lo];
        while (i < j) {
            while (i < j && nums[j] <= curVal) {
                j--;
            }
            if (i < j) {
                nums[i++] = nums[j];
            }
            while (i < j && nums[i] > curVal) {
                i++;
            }
            if (i < j) {
                nums[j--] = nums[i];
            }
        }
        nums[i] = curVal;
        return i;
    }

    int quick_sort(vector<int> &nums, int n, int k) {
        int lo = 0;
        int hi = n - 1;
        while (lo < hi) {
            int cur_idx = partion(nums, lo, hi);
            if (cur_idx == k - 1) {
                break;
            } else if (cur_idx < k - 1) {
                lo = cur_idx + 1;
            } else {
                hi = cur_idx - 1;
            }
        }
        return nums[k - 1];
    }

    /**
        堆排序
    */
    // 调整至最大堆
    void adjust_heap(vector<int> &nums, int lo, int hi) {
        int cur = lo;
        int next = cur * 2 + 1;
        int tmp = nums[cur];
        for (; next <= hi; cur = next, next = next * 2 + 1) {
            if (next < hi && nums[next] < nums[next + 1]) {
                next++;
            }
            if (tmp < nums[next]) {
                nums[cur] = nums[next];
                nums[next] = tmp;
            }
        }
    }

    int heap_sort(vector<int> &nums, int n, int k) {

        int res;

        // 建立最小堆
        for (int i = n / 2 - 1; i >= 0; --i) {
            adjust_heap(nums, i, n - 1);
        }

        for (int i = n - 1; i >= n - k; --i) {
            // int tmp = nums[i];
            res = nums[0];
            nums[0] = nums[i];
            adjust_heap(nums, 0, i - 1);
        }

        return res;
    }

    int findKthLargest(vector<int> &nums, int k) {
        // 堆排序
        // return heap_sort(nums, nums.size(), k);

        // 快速排序
        return quick_sort(nums, nums.size(), k);;

    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << solution->findKthLargest(nums, k);
}

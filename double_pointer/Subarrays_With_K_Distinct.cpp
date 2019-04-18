//
// Created by yzjhh on 2019/4/18.
//
/**
 *
 * 992. Subarrays with K Different Integers
 *
 * Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly K.
 * (For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)
 * Return the number of good subarrays of A.
 *
 * 题目描述：找到数组中恰好有k个不同数字的子数组
 *
 * note：滑动窗口，双指针
 *

Example 1:

Input: A = [1,2,1,2,3], K = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
Example 2:

Input: A = [1,2,1,3,4], K = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].


Note:

1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length
 * */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Window { // window中维护的是i到j中不同元素的个数
private:
    unordered_map<int, int> map; // i到j中每个元素出现的次数
    int diff_count; // 不同元素的个数
public:
    Window() : diff_count(0) {}

    void add(int num) {
        if (map[num] == 0) {
            ++diff_count;
        }
        ++map[num];
    }

    void remove(int num) {
        if (map[num] != 0) {
            --map[num];
        }
        if (map[num] == 0) {
            --diff_count;
        }
    }

    int getDiffCount() {
        return diff_count;
    }
};

class Solution {
public:
    int subarraysWithKDistinct(vector<int> &A, int k) {
        Window *window1 = new Window();
        Window *window2 = new Window();
        int l1 = 0, l2 = 0;
        int res = 0;
        for (int i = 0; i < A.size(); ++i) {
            window1->add(A[i]);
            window2->add(A[i]);

            while (window1->getDiffCount() > k) { // 第一个使得window1中不同元素数量等于k的位置
                window1->remove(A[l1++]);
            }
            while (window2->getDiffCount() >= k) { // 第一个使得window2中不同元素数量等于k-1的位置
                window2->remove(A[l2++]);
            }
            res += l2 - l1;
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    int k = 2;
    vector<int> A = {1, 2, 1, 2, 3};
    cout << solution->subarraysWithKDistinct(A, k);
    return 0;
}
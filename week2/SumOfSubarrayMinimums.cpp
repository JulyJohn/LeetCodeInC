//
// Created by hejunhua on 18-11-21.
//

/**
 * 题目大意：　给出一个整型数组A，找出min(B)的和，其中B涵盖每一个A的邻接子集
 *
 * 由于答案可能会很大，可能会溢出，返回答案的要模10^9+7
 *
 * 例子：　
 * 输入： [3,1,2,4]
 * 输出： 17
 * 解释： 邻接子集有 [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
 * 最小值分别为 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  和为 17.
 *
 *
 * 思路：这道题总体的思想应该是对于某个元素A[I], 在其左右两边找到满足如下条件的数:
 * 左边left: >A[i]
 * 右边right: >=A[i]
 * 这样A[i]就是(l+1)*(r+1)个子序列的最小值
 * */

#include <iostream>
#include <vector>
#include <chrono>
#include <stack>
#include "../util/LeetcodeIO.h"

using namespace std;
using namespace chrono;
using namespace leetcode;

class Solution {
public:
    int sumSubarrayMins(vector<int> &A) { // dp

    }

    int sumSubarrayMins3(vector<int> &A) { // 维护两个单调栈 o(nlgn)
        constexpr int kMod = 1e9 + 7;
        const int n = A.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<pair<int, int>> s;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int len = 1;
            while (!s.empty() && s.top().first > A[i]) {
                len += s.top().second;
                s.pop();
            }
            s.emplace(A[i], len);
            left[i] = len;
        }
        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; --i) {
            int len = 1;
            while (!s.empty() && s.top().first >= A[i]) {
                len += s.top().second;
                s.pop();
            }
            s.emplace(A[i], len);
            right[i] = len;
        }
        for (int i = 0; i < n; ++i)
            ans = (ans + static_cast<long>(left[i]) * A[i] * right[i]) % kMod;
        return ans;
    }

    int sumSubarrayMins2(vector<int> &A) { // 超时不通过 o(n^2)
        constexpr int mod_k = int(1e9) + 7;
        int ans = 0;
        const int n = A.size();
        for (int i = 0; i < n; ++i) {
            int left = 1;
            for (int j = i - 1; j >= 0; --j) {
                if (A[j] > A[i]) {
                    ++left;
                } else {
                    break;
                }
            }
            int right = 1;
            for (int j = i + 1; j < n; ++j) {
                if (A[j] >= A[i]) {
                    ++right;
                } else {
                    break;
                }
            }
            ans = (ans + A[i] * left * right) % mod_k;
        }
        return ans;
    }

    int sumSubarrayMins1(vector<int> &A) { // 超时不通过 o(n^2)
        int mod_k = int(1e9) + 7;
        int sum = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
            if (sum >= mod_k) {
                sum %= mod_k;
            }
            int min_val = A[i];
            for (int j = i + 1; j < A.size(); ++j) {
                if (A[j] < min_val) {
                    min_val = A[j];
                }
                sum += min_val;
                if (sum >= mod_k) {
                    sum %= mod_k;
                }
            }
        }
        return sum;
    }
};

int main() {
    vector<int> A;
//    A = {3, 1, 2, 4};
    string vec_file = "week2/large_vector_for_sosm.txt";
    readVectorFromTxt(vec_file, A);

    Solution *s = new Solution();
    auto func_beg = system_clock::now();
    int loop_cnt = 10;
    int ans = 0;
    for (int i = 0; i < loop_cnt; ++i) {
        ans = s->sumSubarrayMins2(A);
    }
    auto func_end = system_clock::now();
    cout << "func_time: " << duration_cast<milliseconds>(func_end - func_beg).count() / loop_cnt << endl;
    cout << "sum: " << ans << endl;
    cout << "hello world!~" << endl;
}
//
// Created by yzjhh on 2019/3/16.
//

/**
 *
 * 646. Maximum Length of Pair Chain
 *
 * You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.\
 * Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.
 * Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.
 *
 * 题目描述：最长区间链，要求上一个区间的末端必须小于下一个区间的首端
 *
 * Note: 先排序，再找最长递增子序列
 *

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
Note:
The number of given pairs will be in the range [1, 1000].
 * */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void swap(vector<vector<int>> &pairs, int i, int j) {
        vector<int> tmp = pairs[i];
        pairs[i] = pairs[j];
        pairs[j] = tmp;
    }

    void sortByHead(vector<vector<int>> &pairs, int lo, int hi) {
        if (lo >= hi) {
            return;
        }
        int lt = lo;
        int gt = hi + 1;
        int base = pairs[lo][0];
        while (1) {
            while (pairs[++lt][0] < base) {
                if (lt == hi) {
                    break;
                }
            }
            while (pairs[--gt][0] > base) {
                if (gt == lo) {
                    break;
                }
            }
            if (lt >= gt) {
                break;
            }
            swap(pairs, lt, gt);
        }
        swap(pairs, gt, lo);
        sortByHead(pairs, lo, gt - 1);
        sortByHead(pairs, gt + 1, hi);
    }

    int findLongestChain(vector<vector<int>> &pairs) {
        int n = pairs.size();
        if (n < 2) {
            return n;
        }
        sortByHead(pairs, 0, n - 1);
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int max_len = dp[0];
        for (int i = 1; i < n; ++i) {
            max_len = dp[i] > max_len ? dp[i] : max_len;
        }
        return max_len;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<vector<int>> pairs = {
            {3, 4},
            {2, 3},
            {1, 2}
//            {-10, -8},
//            {8,   9},
//            {-5,  0},
//            {6,   10},
//            {-6,  -4},
//            {1,   7},
//            {9,   10},
//            {-4,  7}
    };

    solution->findLongestChain(pairs);
    return 0;
}

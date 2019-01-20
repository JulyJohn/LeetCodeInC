//
// Created by yzjhh on 2018/11/25.
//

/**
 *
898. Bitwise ORs of Subarrays

We have an array A of non-negative integers.
For every (contiguous) subarray B = [A[i], A[i+1], ..., A[j]] (with i <= j),
we take the bitwise OR of all the elements in B, obtaining a result A[i] | A[i+1] | ... | A[j].
Return the number of possible results.
(Results that occur more than once are only counted once in the final answer.)

 给定一个非负整型数组。对每一个连续的子数组 B = [A[i], A[i+1], ..., A[j]] (with i <= j),
 我们计算B中所有元素的位或，得到一个结果 A[i] | A[i+1] | ... | A[j].
 返回可能的结果的数量。（）


Example 1:

Input: [0]
Output: 1
Explanation:
There is only one possible result: 0.

Example 2:

Input: [1,1,2]
Output: 3
Explanation:
The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
These yield the results 1, 1, 2, 1, 3, 3.
There are 3 unique values, so the answer is 3.

Example 3:

Input: [1,2,4]
Output: 6
Explanation:
The possible results are 1, 2, 3, 4, 6, and 7.

 * */


#include <iostream>
#include <vector>
#include <chrono>
#include <unordered_set>

using namespace std;
using namespace chrono;

typedef int Dtype;

class Solution {
public:

    /**
     * 基本思路：
        dp[i][j] := A[i] | A[i + 1] | … | A[j]
        dp[i][j] = dp[i][j – 1] | A[j]
        ans = len(set(dp))
     * */

    int subarrayBitwiseORs(vector<int> &A) {
        unordered_set<int> res, cur, cur2;
        for (int i: A) {
            cur2 = {i};
            for (int j: cur) {
                cur2.insert(i | j);
            }
            cur = cur2;
            for (int j: cur) {
                res.insert(j);
            }
        }
        return res.size();
    }

    // 直接用dp会TLE
    int subarrayBitwiseORs1(vector<int> &A) {
        const unsigned long n = A.size();
        vector<vector<int>> dp(n, vector<int>(n));
        unordered_set<int> ans(begin(A), end(A));
        for (int l = 1; l <= n; ++l) { // 与当前元素的距离
            for (int i = 0; i <= n - l; ++i) { // 遍历A中元素， 到n-l为止
                int j = i + l - 1;
                if (l == 1) { // 1表示当前元素本身
                    dp[i][j] = A[i];
                    continue;
                }
                dp[i][j] = dp[i][j - 1] | A[j];
                ans.insert(dp[i][j]);
            }
        }

        // 上述过程可以简化成如下形式：
//        vector<int> dp(A); // 距离为1的情况实际上就是A本身
//        unordered_set<int> ans(begin(A), end(A));
//        for (int l = 1; l <= n; ++l) { // 从距离为2的情况开始
//            for (int i = 0; i <= n - l; ++i) {
//                ans.insert(dp[i] |= A[i + l - 1]);
//            }
//        }

        return ans.size();
    }
};

int main() {
    Solution *s = new Solution();
    int vector_size = 3;
    vector<int> A = {1, 1, 4};

    auto func_beg = system_clock::now();
    long loop_num = 1;
    for (int i = 0; i < loop_num; ++i) {
        int ans = s->subarrayBitwiseORs(A);
        cout << "ans: " << ans << endl;
    }
    auto func_duration = duration_cast<milliseconds>(system_clock::now() - func_beg);
    cout << endl << "func_duaration: " << func_duration.count() << endl;
}
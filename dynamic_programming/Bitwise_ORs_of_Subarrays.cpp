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
    // 用一个set来保存上一次的结果状态，这样就可以减少重复比较的情况，时间复杂度为o(32n)
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> prev;
        unordered_set<int> cur;
        unordered_set<int> res;
        for(int a : A){
            cur = {a};
            for(int cur_item : prev){
                cur.insert(a | cur_item);
            }
            prev = cur;
            for(int cur_item : cur){
                res.insert(cur_item);
            }
        }
        return res.size();
    }
    /**
     * 基本思路：
        dp[i][j] := A[i] | A[i + 1] | … | A[j]
        dp[i][j] = dp[i][j – 1] | A[j]
        ans = len(set(dp))
     * */
    // 直接用dp会TLE
     int subarrayBitwiseORs(vector<int>& A) {
         int n = A.size();
         vector<vector<int > > dp(n+1, vector<int >(n+1, 0));
         unordered_set<int > res;
         for(int i = 1; i <= n; ++i){
             for(int j = i; j <= n; ++j){
                 dp[i][j] = dp[i][j-1] | A[j-1];
                 res.emplace(dp[i][j]);
             }
         }
         return res.size();
     }
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
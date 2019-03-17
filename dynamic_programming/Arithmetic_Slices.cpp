//
// Created by yzjhh on 2019/3/17.
//

/**
 *
 * 413. Arithmetic Slices
 *
 * A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
 *
 * 题目描述：找出数组中等差递增子区间的个数

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.


Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
 * */

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 3){
            return 0;
        }
        vector<int > dp(n, 0);
        for(int i = 2; i < n; ++i){
            if(A[i-1] - A[i-2] == A[i] - A[i-1]){
                dp[i] = dp[i-1] + 1;
            }
        }
        int res = 0;
        for(int i = 2; i < n; ++i){
            res += dp[i];
        }
        return res;
    }
};
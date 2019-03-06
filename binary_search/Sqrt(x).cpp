//
// Created by yzjhh on 2019/3/6.
//

/**
 * 69. Sqrt(x)
 *
 * Implement int sqrt(int x).
 *
 * 题目描述： 实现一个开方，有小数的情况只保留整数位。
 *
 * note: 注意若是相乘会溢出，所以要用除法
 *

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since
             the decimal part is truncated, 2 is returned.
 *
 * */

#include <iostream>


class Solution {
public:
    int mySqrt(int x) {
        int lo = 1;
        int hi = x;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            int sqrt = x / mid;
            if(sqrt == mid){
                return mid;
            }else if(sqrt > mid){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        return hi;
    }
};
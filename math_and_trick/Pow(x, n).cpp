//
// Created by yzjhh on 2019/3/31.
//

/**
 *
 * 50. Pow(x, n)
 * Implement pow(x, n), which calculates x raised to the power n (xn).
 *
 * 题目描述：实现pow(x, n)，递归和非递归
 *
 * note：
 * 1. 关于（1）中对于负指数情况的处理，会存在边界问题，即int范围中，负数比正数多一个数。
 * 若将 -n 直接变成 n ，在 -n 为 −2^31 时， n 为 2^31，超出了int的范围。
 * 令 n’ = n+1 = -2147483647 。求x^n等价于求 x^n’ * x-1
 *

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
 * */


class Solution {
public:
    // 非递归版本
    double myPow(double x, int n){
        unsigned int _n;
        _n = n < 0 ? -(n+1) : n;
        double res = 1;
        double tmp_pow = x;
        while(_n){
            if(_n&1){
                res *= tmp_pow;
            }
            _n >>= 1;
            tmp_pow *= tmp_pow;
        }
        return n < 0 ? 1.0 / (res * x) : res;
    }

    // 递归版本
    // double myPow(double x, int n) {
    //     if(n == 0){
    //         return 1;
    //     }
    //     double half = myPow(x, n/2);
    //     if(n % 2){
    //         return n < 0 ?  1.0 / x * half * half : x * half * half;
    //     }else{
    //         return half * half;
    //     }
    // }
};
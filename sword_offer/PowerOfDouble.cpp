//
// Created by yzjhh on 2019/3/8.
//

/**
 *
 * 16. 数值的整数次方
 *
 * 求一个浮点数的整数次幂，要求时间复杂度为O(logn)
 * */
#include <iostream>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        int n = exponent;
        if(exponent == 0){
            return 1;
        } else if(exponent < 0){
//            if(base == 0){ // 0没有负次幂，所以这里应该抛一个异常
//                return 0;
//            }
            n = -n;
        }
        int res = powerHelper(base, n);
        return exponent < 0 ? 1. / res : res;
    }

    double powerHelper(double base, int exponent) {
        if (exponent == 1) {
            return base;
        }

        int res = powerHelper(base, exponent / 2);

        res *= res;

        // exponent为奇数的时候，只有第一次进来的时候为基数，不然除一次2以后就会变成偶数
        // 所以这句代码只可能在最后一步的时候执行一次
        if(exponent & 0x1){
            res *= base;
        }

        return res;
    }
};

int main() {
    int base = 3;
    int exponent = -2;

    Solution *solution = new Solution();
    cout << solution->Power(base, exponent);
    return 0;
}
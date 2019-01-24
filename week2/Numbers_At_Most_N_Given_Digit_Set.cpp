//
// Created by yzjhh on 2019/1/22.
//

/**
 *
 * 902. Numbers At Most N Given Digit Set

We have a sorted set of digits D, a non-empty subset of {'1','2','3','4','5','6','7','8','9'}.  (Note that '0' is not included.)

Now, we write numbers using these digits, using each digit as many times as we want.  For example, if D = {'1','3','5'}, we may write numbers such as '13', '551', '1351315'.

Return the number of positive integers that can be written (using the digits of D) that are less than or equal to N.

题目大意：
 有一个排序好的数字集D，是{'1','2','3','4','5','6','7','8','9'}的一个非空子集。（不包括0）
 现在，用这些数字来写数，每个数字可以用任意次，例如，假如D = {'1','3','5'}，我们可以写出的数有'13', '551', '1351315'.
 返回小于等于N的所有可能的结果的数量。

Example 1:

Input: D = ["1","3","5","7"], N = 100
Output: 20
Explanation:
The 20 numbers that can be written are:
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
Example 2:

Input: D = ["1","4","9"], N = 1000000000
Output: 29523
Explanation:
We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
In total, this is 29523 integers that can be written using the digits of D.


Note:

D is a subset of digits '1'-'9' in sorted order.
1 <= N <= 10^9
 * */

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:

    /**
     * 解题思路：以D = {1， 3， 5， 7}， N=5371为例
     * 首先比5371位数小的都满足 xxx, xx, xx，总共有：4*4*4 + 4*4 + 4个
     * 与5371位数相同的，
     * 1. 先看首位，小于5的肯定满足：
     *    3XXX
     *    1XXX
     *    总共有：2*4*4*4个
     * 2. 等于5的情况，再看下一位，小于3的肯定满足：
     *    51XX
     *    总共有：4*4个
     * 3. 等于3的情况，看下一位，小于7的肯定满足：
     *    535X
     *    533X
     *    531X
     *    总共有：3*4个
     * 4. 等于7的情况，看下一位，因为是最后一位了，因此小于等于1的都能满足：
     *    5371
     *    总共有： 1个
     *
     * 可以看出：主线的算法应该是从N的最高位到最低位遍历下去，存在以下几种情况：
     *    1. D中所有数字都大于当前位，说明当前位没有任何可能的取值，那么遍历结束，返回当前res
     *    2. D从某个数字d开始小于当前位，说明从d开始比它小的数都是当前位可以取到的值，那么遍历结束，返回当前res
     *    3. D从某个数字d开始等于当前位，说明比d小的数都是满足条件的，
     *       但是d是否满足还得看N的下一位，那么跳到N的下一位，继续与D中数据比较；
     *
     *  如果完成了整个N的遍历，说明最后一次比较是等于的情况，但是我们在3中并没有包含这一情况，因此结果还要加1
     * */
    int atMostNGivenDigitSet(vector<string> &D, int N) {
        int res = 0;
        string N_str = to_string(N);
        int N_len = N_str.length();
        int D_len = D.size();

        for (int i = 1; i < N_len; ++i) { // 比N位数小的，都是满足条件的
            res += pow(D_len, i);
        }

        // 考虑与N位数相同的情况
        for (int i = 0; i < N_len; ++i) {
            char c = N_str[i];
            for (int j = D_len - 1; j >= 0; --j) {
                char d = D[j][0];
                if (d > c) {
                    if (j == 0) { // 边界条件1: 如果j到0了，说明D中所有的数都比N当前位置的数大，当前位可能的数量为0，此时无需再继续往下比
                        return res;
                    }
                } else if (d < c) { // 如果 d < c, 说明不用再比下去了，当前位的可能数量为小于等于d的数量
                    res += pow(D_len, N_len - i - 1) * (j + 1);
                    return res;
                } else { // d == c, 则继续比较C的下一位，当前位的可能数量为小于d的数量（不包括d）
                    res += pow(D_len, N_len - i - 1) * j;
                    break;
                }
            }
        }
        return res + 1;
    }
};

int main() {
    vector<string> D = {"1", "3", "5", "7"};
    int N = 5371;
//    vector<string> D = {"5", "6"};
//    int N = 19;
    Solution *solution = new Solution();
    cout << solution->atMostNGivenDigitSet(D, N) << endl;
    return 0;
}
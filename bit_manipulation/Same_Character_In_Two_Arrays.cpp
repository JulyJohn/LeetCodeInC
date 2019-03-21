//
// Created by yzjhh on 2019/3/21.
//
/**
 *
 * 判断两个字符串中是否有相同字符
 *
 * note：用一个int(32位)数来做bit map，26个字母可以分别映射到26个不同的位上。
 *      最后再比较两个bit_map，如果有相同字符，那么结果一定有一位为1。
 *
 * */

class Solution {
public:
    bool hasSameCharacter(string a, string b) {
        int bit_map_a = 0;
        int bit_map_b = 0;
        for (char c_a : a) {
            a &= 1 >> (c_a - 'a');
        }
        for (char c_b : b) {
            b &= 1 >> (c_b - 'a');
        }
        return a & b;
    }
};
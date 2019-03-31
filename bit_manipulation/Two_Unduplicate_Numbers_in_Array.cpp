//
// Created by yzjhh on 2019/3/19.
//

/**
 *
 * 数组中只有两个单独出现的数字,其余全是重复两次出现的.找出这两个数.
 *
 * */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void findTwoUnduplicateNumbers(vector<int> nums, int &x, int &y) {
        int n = nums.size();
        int xor_res = 0;
        for (int num : nums) {
            xor_res ^= num;
        }
        int one_pos;
        for (int i = 0; i < 32; ++i) {
            if ((xor_res >> i) & 1) {
                one_pos = i;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {

        }

    }
};
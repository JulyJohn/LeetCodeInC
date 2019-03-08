//
// Created by yzjhh on 2019/3/8.
//

/**
 *
 * 21. 调整数组顺序使奇数位于偶数前面
 *
 * 题目描述：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 * */
#include <vector>

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int n = array.size();
        int last_idx = n;
        for(int i = 0; i < n - 1; ++i){
            int pos = 0;
            for(int j = 1; j < last_idx; ++j){
                if(!(array[j-1]&0x1) && array[j]&0x1){
                    int tmp = array[j];
                    array[j] = array[j-1];
                    array[j-1] = tmp;
                    pos = j;
                }
            }
            last_idx = pos;
        }
    }
};
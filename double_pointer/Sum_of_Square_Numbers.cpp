//
// Created by yzjhh on 2019/2/4.
//

/**
 *
 * 633. Sum of Square Numbers

 Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

 题目大意： 给出一个非负整数c，判断是否存在两个整数a和b满足a2 + b2 = c.

Example 1:

Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5


Example 2:

Input: 3
Output: False
 * */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int idx1 = 0;
        int idx2 = sqrt(c);
        while(idx1 <= idx2){
            int square_sum = idx1 * idx1 + idx2 * idx2;
            if(square_sum > c){
                idx2--;
            }else if(square_sum < c){
                idx1++;
            } else{
                return true;
            }
        }
        return false;
    }
};

int main() {
    int c = 1000000;
    Solution *solution = new Solution();
    bool ans = solution->judgeSquareSum(c);
    cout << ans;
}
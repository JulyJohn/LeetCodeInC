//
// Created by yzjhh on 2019/3/18.
//

/**
 *
 * 650. 2 Keys Keyboard
 *
 * Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:
 * Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
 * Paste: You can paste the characters which are copied last time.
 * Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.
 *
 * 题目描述：起初有一个'A'，为了要获得n个'A'，现在可以通过复制粘贴来实现，要求
      1. 复制的时候必须复制所有的内容
      2. 粘贴之前必须先复制
  求最少需要多少次操作才能获取n个'A'

  note：设dp[i]为获取i个'A'所需的最下操作次数，那么为了使操作次数尽可能地小，就要复制的时候尽可能地复制的多，
        例如对于6来说，可以通过复制2次3个'A'或者复制3次2个'A'来得到。
        而这个可以复制的原始字符串大小又必须要求能被6整除，据此可以列出公式：
        dp[i] = min(dp[i], dp[j] + j / i), j%i == 0

Example 1:

Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.


Note:

The n will be in the range [1, 1000].
 *
 * */

class Solution {
public:
    int minSteps(int n) {
        vector<int > dp(n + 1, 0);
        for(int i = 2; i <= n; ++i){
            dp[i] = i;
            for(int j = i-1; j >= 1; j--){
                if(i % j == 0){
                    dp[i] = min(dp[i], dp[j] + i/j);
                }
            }
        }
        return dp[n];
    }
};
//
// Created by yzjhh on 2019/3/18.
//

/**
 *
 * 392. Is Subsequence
 *
 * 题目描述：判断s是否为t的字串
 *
 * */


class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m > n){
            return false;
        }
        int i = 0;
        int j = -1;
        while(++j < n){
            if(s[i] == t[j]){
                ++i;
            }
        }
        return i == m;
    }
};
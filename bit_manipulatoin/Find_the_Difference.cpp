//
// Created by yzjhh on 2019/3/19.
//

/**
 *
 * 389. Find the Difference
 *
 * note: 异或. X ^ X = 0, X ^ 0 = X
 *
 * */

class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = t.length();
        char res = 0;
        for(char s_c : s){
            res ^= s_c;
        }
        for(char t_c : t){
            res ^= t_c;
        }
        return res;
    }
};
//
// Created by yzjhh on 2019/3/27.
//

/**
 *
 * 5. Longest Palindromic Substring
 *
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 * 题目描述：找到最大的回文子串

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
 *
 * */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    string longestPalindrome(string s) {
        int n = s.length();
        int i = 0;
        int start;
        int end;
        int tmp_len;
        int max_len = 1;
        int pos = 0;
        while(i < n){
            start = i;
            end = i;
            // 跳过重复的字符串
            while(end < n-1 && s[end+1] == s[end]){
                ++end;
            }
            i = end + 1; // 更新i
            // 两边扩张，注意此时start和end标记的分别是重复串的起始点
            while(start > 0 && end < n-1 && s[start-1] == s[end+1]){
                --start;
                ++end;
            }
            tmp_len = end - start + 1;
            if(tmp_len > max_len){
                max_len = tmp_len;
                pos = start;
            }
        }
        return s.substr(pos, max_len);
    }

//    string longestPalindrome(string s) {
//        int n = s.length();
//        int max_len = 0;
//        int max_len1 = 0;
//        int max_len2 = 0;
//        int pos = 0;
//        for (int i = 0; i < n; ++i) { // 以每个字符向两边扩散，寻找最大回文
//            max_len1 = lps_helper(s, i, i);
//            max_len2 = lps_helper(s, i, i + 1);
//            if (max_len1 > max_len2 && max_len1 > max_len) {
//                max_len = max_len1;
//                pos = i - (max_len1 - 1) / 2;
//            } else if (max_len2 > max_len1 && max_len2 > max_len) {
//                max_len = max_len2;
//                pos = i - max_len2 / 2 + 1;
//            }
//            if(max_len >= (n - i + 1) * 2){ // 如果剩余长度小于当前已经获取到的最大长度，则停止循环
//                break;
//            }
//        }
//        return s.substr(pos, max_len);
//    }
//
//    int lps_helper(string s, int i, int j) {
//        int max_len = i == j ? -1 : 0;
//        while (i >= 0 && j < s.length() && s[i] == s[j]) {
//            max_len += 2;
//            --i;
//            ++j;
//        }
//        return max_len;
//    }
};


int main() {
    Solution *solution = new Solution();
    string s = "a";
    solution->longestPalindrome(s);
    return 0;
}
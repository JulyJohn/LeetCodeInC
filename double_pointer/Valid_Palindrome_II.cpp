//
// Created by yzjhh on 2019/2/6.
//

/**
 * 680. Valid Palindrome II

 Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

 题目大意：给出一个非空字符串s，你最多可以刪除一个字符，判断你是否可以使它变成一个回文

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
 * */
#include <iostream>

using namespace std;

class Solution {
public:
    bool is_palindrome(string s, int start_idx, int end_idx) {
        while (start_idx < end_idx) {
            if (s[start_idx++] != s[end_idx--]) {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int idx1 = 0;
        int idx2 = s.size() - 1;
        while (idx1 < idx2) {
            if (s[idx1++] != s[idx2--]) {
                return is_palindrome(s, idx1 + 1, idx2) || is_palindrome(s, idx1, idx2 - 1);
            }
        }
        return true;
    }

    bool validPalindrome2(string s) {
        int idx1 = 0;
        int idx2 = s.size() - 1;
        int idx3 = idx1;
        int idx4 = idx2;
        bool has_deleted = false;
        bool left_flag = true;
        while (idx1 < idx2) {
            if (s[idx1] != s[idx2]) {
                if (has_deleted) {
                    left_flag = false;
                    break;
                }
                if (s[idx1 + 1] == s[idx2]) {
                    idx3 = idx1;
                    idx4 = idx2;
                    idx1 += 2;
                    idx2--;
                    has_deleted = true;
                } else {
                    left_flag = false;
                    break;
                }
            } else {
                idx1++;
                idx2--;
            }
        }

        has_deleted = false;
        bool right_flag = true;
        while (idx3 < idx4) {
            if (s[idx3] != s[idx4]) {
                if (has_deleted) {
                    right_flag = false;
                    break;
                }
                if (s[idx3] == s[idx4 - 1]) {
                    idx3++;
                    idx4 -= 2;
                    has_deleted = true;
                } else {
                    right_flag = false;
                    break;
                }
            } else {
                idx3++;
                idx4--;
            }
        }
        return left_flag || right_flag;
    }
};

int main() {
    Solution *solution = new Solution();
    string s = "abakk";
//    string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    cout << solution->validPalindrome(s);
}
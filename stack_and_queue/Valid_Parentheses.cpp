//
// Created by yzjhh on 2019/3/5.
//

/**
 *
 * 20. Valid Parentheses
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * 题目描述：用栈实现括号匹配

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
 * */
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> bs;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                bs.push(s[i]);
            } else if (bs.empty()) {
                return false;
            } else if ((bs.top() == '(' && s[i] == ')') || (bs.top() == '[' && s[i] == ']') ||
                       (bs.top() == '{' && s[i] == '}')) {
                bs.pop();
            } else {
                return false;
            }
        }
        return bs.empty();
    }
};

int main() {
    string s = "";
    cout << s.length();
    return 0;
}
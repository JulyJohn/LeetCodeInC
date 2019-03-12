//
// Created by yzjhh on 2019/3/12.
//

/**
 *
 * 150. Evaluate Reverse Polish Notation
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * 
 * 题目描述：带有+, -, *, /的表达式求值
 *

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation:
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 * */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int > s;
        int val1;
        int val2;
        int res;
        for(int i = 0; i < n; ++i){
            string cur_str = tokens[i];
            if(cur_str.length() == 1 && (cur_str[0] == '+' || cur_str[0] == '-' || cur_str[0] == '*' || cur_str[0] == '/')){
                val1 = s.top();
                s.pop();
                val2 = s.top();
                s.pop();
                if(cur_str[0] == '+'){
                    res = val1 + val2;
                }else if(cur_str[0] == '-'){
                    res = val2 - val1;
                }else if(cur_str[0] == '*'){
                    res = val1 * val2;
                }else{
                    res = val2 / val1;
                }
                s.push(res);
            }else{
                s.push(atoi(cur_str.c_str()));
            }
        }
        res = s.top();
        return res;

    }
};
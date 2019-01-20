//
// Created by yzjhh on 2019/1/20.
//

/**
 * 13. Roman to Integer
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

 题目大意： 罗马数字由七种不同形式的符号来表示，I, V, X, L, C, D及M分别代表1, 5, 10, 50, 100, 500, 1000。
 例如，2用罗马数字的方式可以写作II，12写作XII，27可以写作XXVII
 罗马数字通常按照从大到小、从左至右的方式来书写。然而，数字4确不写做IIII。相反的，数字4写作IV，数字9写作IX。
 类似的情况有6种：
 I放在V和X之前来表示4和9；
 X放在L和C前面来表示40和90；
 C放在D和M前面来表示400和900；

 现给出一个罗马数字，将其转换成一个数字。输入数据范围在1到3999之间。
 
Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    int romanToInt(string s) {
        if(s.length() == 0){
            return 0;
        }
        map<char, int> lookup_table;
        lookup_table.insert({'I', 1});
        lookup_table.insert({'V', 5});
        lookup_table.insert({'X', 10});
        lookup_table.insert({'L', 50});
        lookup_table.insert({'C', 100});
        lookup_table.insert({'D', 500});
        lookup_table.insert({'M', 1000});

        int prev = lookup_table.find(s[0])->second;
        int cur = 0;
        int res = prev;
        for (int i = 1; i < s.length(); ++i) {
            cur = lookup_table.find(s[i])->second;
            res += cur;
            if(cur > prev){
                res -= 2 * prev;
            }
            prev = cur;
        }

        return res;
    }
};

int main() {
    string s = "LVIII";
    Solution *solution = new Solution();
    cout<< solution->romanToInt(s);
    return 0;
}
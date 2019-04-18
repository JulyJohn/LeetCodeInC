//
// Created by yzjhh on 2019/4/18.
//

/**
 *
 * 表示数值的字符串
 *
 * note：以e为分隔符，分别考虑前半部分和后半部分
 *
 * */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // 以e为分隔符，分别考虑前半部分和后半部分
    bool isNumeric(char *string) {
        int idx = -1;
        int sign_idx1 = -1; // 前半部分符号出现的位置
        int dot_idx = -1; // 小数点出现的位置
        int e_idx = -1; // e出现的位置
        int sign_idx2 = -1; // 后半部分符号出现的位置
        // 特殊符号位的顺序依次为 sign_idx1 < dot_idx < e_idx < sign_idx2
        char c;
        while ((c = string[++idx]) != '\0') {
            // 以e为分隔符，分别考虑前半部分和后半部分
            if (e_idx == -1) { // e没有出现，前半部分
                if ((idx == 0 && (c == '+' || c == '-'))) { // 首字符可以是+-号
                    sign_idx1 = idx;
                    continue;
                }
                if (dot_idx == -1 && c == '.') { // 记录小数点出现的位置
                    dot_idx = idx;
                    continue;
                }
                if (c == 'e' || c == 'E') { // 记录e出现的位置
                    e_idx = idx;
                    continue;
                }
            } else { // e出现了，后半部分
                if (c == '.') { // e后面不能有小数点
                    return false;
                }
                if (idx == e_idx + 1 && (c == '-' || c == '+')) { // 只有e的下一位可以是-+号
                    sign_idx2 = idx;
                    continue;
                }
            }
            if ((c < '0' || c > '9')) { // 其他情况，如果不是数字都是非法的
                return false;
            }
        }
        // 最后，保证e的前半部分和后半部分中至少有一位是数字
        // 等于说，字符串中最后一次出现的特殊符号后面必须要跟着至少一个数字（小数点除外）
        return e_idx == -1 ? dot_idx == -1 ? sign_idx1 == -1 ? idx > 0 : idx > sign_idx1 + 1 : idx > dot_idx :
               sign_idx2 == -1 ? idx > e_idx + 1 : idx > sign_idx2 + 1;
    }

};


int main() {
    Solution *solution = new Solution();
    char *str = "+.123";
    cout << solution->isNumeric(str);
    return 0;
}
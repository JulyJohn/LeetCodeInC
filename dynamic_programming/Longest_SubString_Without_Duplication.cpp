//
// Created by julyjohn on 2019-04-09.
//

/**
 *
 * 最长不含重复字符的子字符串
 *
 * 题目描述：输入一个字符串（只包含 a~z 的字符），求其最长不含重复字符的子字符串的长度。例如对于 arabcacfr，最长不含重复字符的子字符串为 acfr，长度为 4。
 * */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    int longestSubStringWithoutDuplication(string str){
        int cur_len = 0; // 表示当前没有重复字符的字串长度
        int max_len = 0;
        int n = str.length();
        vector<int > record(26, -1);
        int pre_idx = 0;
        for (int i = 0; i < n; ++i) {
            pre_idx = record[str[i] - 'a']; // pre_idx = -1时，表示该单词之前没有出现过，否则则表示该单词最近一次出现的位置是pre_idx
            if(pre_idx == -1 || i - pre_idx > cur_len){ // 如果当前位置单词没有出现，或者到上一次出现的位置的距离大于cur_len，则说明对cur_len没有影响
                ++cur_len;
            }else{
                max_len = max(max_len, cur_len);
                cur_len = i - pre_idx;
            }
            record[str[i] - 'a'] = i; // 记录下当前字符最新出现的位置
        }
        return max_len;
    }
};

int main(){
    string str = "arabcacfr";
    Solution *solution = new Solution();
    cout << solution->longestSubStringWithoutDuplication(str);
    return 0;
}
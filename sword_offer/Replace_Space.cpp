//
// Created by yzjhh on 2019/3/6.
//

/**
 *
 * 5. 替换空格
 *
 * 题目描述：将一个字符串中的空格替换成 "%20"。
 *
 * */

class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(length < 1){
            return;
        }
        int new_length = length;
        // 每碰到一个空格，给字符串的末尾加两个长度
        for(int i = 0; i < length; ++i){
            if(str[i] == ' '){
                new_length += 2;
            }
        }
        // 用两个指针，p1指向旧字符串的末尾，p2指向新字符串的末尾，每当碰到空格的时候就让p2向前移动三个长度，依次填入‘%’‘2’‘0’，否则让p2填入p1指向的字符
        int p1 = length - 1;
        int p2 = new_length - 1;
        while(p1 >= 0 && p2 >= p1){
            if(str[p1] == ' '){
                str[p2--] = '0';
                str[p2--] = '2';
                str[p2--] = '%';
            }else{
                str[p2--] = str[p1];
            }
            --p1;
        }
    }
};
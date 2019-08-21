//
// Created by yzjhh on 2019/8/21.
//

/**
 * 基本字符串压缩
 *
 * 题目描述：利用字符重复出现的次数，编写一个方法，实现基本的字符串压缩功能。比如，字符串“aabcccccaaa”经压缩会变成“a2b1c5a3”。若压缩后的字符串没有变短，则返回原先的字符串。
 * 测试样例：
 * "aabcccccaaa"
 * 返回："a2b1c5a3"
 * "welcometonowcoderrrrr"
 * 返回："welcometonowcoderrrrr"
 *
 * */
class Zipper {
public:
    string zipString(string s) {
        // write code here
        string res = "";
        int strLen = s.length();
        int i = 0;
        while(i < strLen){
            int cnt = 1;
            if(i + 1 < strLen && s[i + 1] == s[i]){
                int j = i + 1;
                ++cnt;
                while(++j < strLen && s[j] == s[i]){
                    ++cnt;
                }
                res += s[i] + to_string(cnt);
                i = j;
            }else{
                res += s[i] + to_string(cnt);
                ++i;
            }
        }
        return res.length() >= strLen ? s : res;
    }
};
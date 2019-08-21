//
// Created by yzjhh on 2019/8/21.
//

/**
 *
 * 翻转子串
 * 题目描述：假定我们都知道非常高效的算法来检查一个单词是否为其他字符串的子串。请将这个算法编写成一个函数，给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成，要求只能调用一次检查子串的函数。
 *
 * 测试样例：
 * "Hello world","worldhello "
 * 返回：false
 * "waterbottle","erbottlewat"
 * 返回：true
 * */

class ReverseEqual {
public:
    bool checkReverseEqual(string s1, string s2) {
        // write code here
        if(s1.length() != s2.length() || s1.length() == 0 || s2.length() == 0){
            return false;
        }
        string s = s1 + s1;
        if(s.find(s2) == -1){
            return false;
        }
        return true;
    }
};
//
// Created by yzjhh on 2019/8/12.
//

/**
 * 正则表达式匹配
 *
 * 请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。
 * 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
 *
 * */
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(str == NULL || pattern == NULL){
            return false;
        }
        return helper(str, pattern, 0, 0);
    }

    bool helper(char* s, char* p, int sIdx, int pIdx){
        if(p[pIdx] == '\0'){ // 以pattern是否遍历完成为标志
            return  s[sIdx] == '\0' ? true : false;
        }
        if(p[pIdx + 1] == '*'){
            // 1. 两种情况可以称为匹配上，
            //      a，两个字符相等；
            //      b. Pattern中为'.'，而Str中不为空
            // 2. 如果x*与y匹配上了，有三种情况:
            //      a. Str不动，忽略该Pattern，继续比较下一个；
            //      b. Str和Pattern同时比较下一个；
            //      c. 继续用这个Pattern去匹配下一个Str中的字符
            if(s[sIdx] == p[pIdx] || (p[pIdx] == '.' && s[sIdx] != '\0')){
                return helper(s, p, sIdx, pIdx + 2) ||
                       helper(s, p, sIdx + 1, pIdx + 2) ||
                       helper(s, p, sIdx + 1, pIdx);
            }else{
                return helper(s, p, sIdx, pIdx + 2);
            }
        }
        if(s[sIdx] == p[pIdx] || (p[pIdx] == '.' && s[sIdx] != '\0')){
            return helper(s, p, sIdx+1, pIdx+1);
        }else{
            return false;
        }
    }
};
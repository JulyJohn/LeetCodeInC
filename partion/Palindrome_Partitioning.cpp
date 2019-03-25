//
// Created by yzjhh on 2019/3/25.
//

/**
 *
 * 131. Palindrome Partitioning
 *
 * Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
 *
 * 题目描述：将一个字符串切分为都是回文的字串，返回所有可能的切分结果。

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
 * */

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string > path;
        partion_helper(s, 0, path, res);
        return res;
    }

    void partion_helper(string s, int pos, vector<string > &path, vector<vector<string>> &res){
        if(pos == s.length()){ // 遍历到s的最尾端时，将当前集合加入到结果中去
            res.push_back(path);
            return;
        }
        for(int i = pos; i < s.length(); ++i){ // 从上一个回文的下一个字符开始往后遍历整个字符串
            string pre_str = s.substr(pos, i-pos+1);
            if(isPalindrome(pre_str)){ // 如果当前字串为回文，那么放入path中，继续往后面找
                path.push_back(pre_str);
                partion_helper(s, i+1, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s){
        int i = 0;
        int j = s.length() - 1;
        while(i < j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
};
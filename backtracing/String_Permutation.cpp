//
// Created by julyjohn on 2019-04-11.
//

/**
 *
 * 字符串的排序
 *
 * 题目描述：输入一个字符串,按字典序打印出该字符串中字符的所有排列。
 * 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
 *
 * */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 另一种解法，dfs
    vector<string> Permutation_dfs(string str) {
        vector<string> res;
        int n = str.length();
        if(n == 0){
            return res;
        }
        sort(str.begin(), str.end());
        vector<bool> visited(n, false);
        string res_str = "";
        dfs_helper(res, str, res_str, visited);
        return res;
    }

    void dfs_helper(vector<string> &res, string &str, string &res_str, vector<bool> &visited){
        if(res_str.length() == str.length()){
            res.push_back(res_str);
            return ;
        }
        for(int i = 0; i < str.length(); ++i){
            if(visited[i]){
                continue;
            }
            if(i != 0 && !visited[i - 1] && str[i] == str[i - 1]){
                continue;
            }
            visited[i] = true;
            res_str.push_back(str[i]);
            dfs_helper(res, str, res_str, visited);
            res_str.pop_back();
            visited[i] = false;
        }
    }

    // 全排列算法：从第一个元素开始，对每个元素，分别与它后面不相同的数交换
    // http://www.cnblogs.com/cxjchen/p/3932949.html
    vector<string> Permutation_math(string str) {
        vector<string> res;
        int n = str.length();
        helper(str, res, 0, n-1);
        sort(res.begin(),res.end());
        return res;
    }

    void helper(string &str, vector<string> &res, int begin, int end){
        if(begin == end){
            res.emplace_back(str);
            return ;
        }
        for(int i = begin; i <= end; ++i){
            if(!has_duplicate(str, begin, i)){
                if(str[begin] != str[i]){
                    swap(str[begin], str[i]);
                }
                helper(str, res, begin + 1, end);
                if(str[begin] != str[i]){
                    swap(str[begin], str[i]);
                }
            }
        }
    }

    // begin~k-1有没有重复元素
    bool has_duplicate(string &str, int begin, int k){
        for (int i = begin; i < k; ++i) {
            if(str[i] == str[k]){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution *solution = new Solution();
    string str = "";
    vector<string> res = solution->Permutation_dfs(str);
    return 0;
}
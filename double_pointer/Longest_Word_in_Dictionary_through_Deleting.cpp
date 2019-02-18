//
// Created by yzjhh on 2019/2/10.
//

/**
 * 524. Longest Word in Dictionary through Deleting
 *
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

 题目大意：
 给出一个字符串和字符字典，删除 s 中的一些字符，使得它构成字符串列表 d 中的一个字符串，找出能构成的最长字符串。
 如果有多个相同长度的结果，返回字典序的最小字符串。

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output:
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output:
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.
 *
 * */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s, string target) {
        int i = 0;
        int j = 0;
        while (i < s.length() && j < target.length()) {
            if (s[i] == target[j]) {
                j++;
            }
            i++;
        }
        return j == target.length();
    }

    string findLongestWord(string s, vector<string> &d) {
        string longestWorld = "";
        for (int i = 0; i < d.size(); ++i) {
            string target = d[i];
            int l1 = longestWorld.length();
            int l2 = target.length();
            if (l2 < l1 || (l1 == l2 && longestWorld.compare(target) < 0)) { // 如果比之前找到的最长字符串短或者比它小，则跳过
                continue;
            }
            if (isValid(s, target)) {
                longestWorld = target;
            }
        }
        return longestWorld;
    }
};

int main() {
    Solution *solution = new Solution();
    string s = "abpcplea";
    vector<string> d = {"a","b","c"};
    cout << solution->findLongestWord(s, d);
    return 0;
}
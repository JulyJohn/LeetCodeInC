//
// Created by yzjhh on 2019/2/23.
//

/**
 *
 * 451. Sort Characters By Frequency
 *
 * Given a string, sort it in decreasing order based on the frequency of characters.
 *
 * 题目大意： 给出一个字符串，基于字符的出现频率以降序的方式对字符串中的字符进行排序

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 * */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> char_freq;
        for (int i = 0; i < n; ++i) {
            char_freq[s[i]]++;
        }

        vector<vector<char >> bucket(n + 1);
        unordered_map<char, int>::iterator it = char_freq.begin();
        while (it != char_freq.end()) {
            bucket[it->second].push_back(it->first);
            it++;
        }

        string res = "";
        for (int i = n; i > 0; --i) {
            int bucket_size = bucket[i].size();
            if (bucket_size != 0) {
                for (int j = 0; j < bucket_size; ++j) {
                    int freq = i;
                    while (freq-- > 0) {
                        res += bucket[i][j];
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    string s = "ccaaa";
    cout << solution->frequencySort(s);
}
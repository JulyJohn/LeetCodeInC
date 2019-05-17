//
// Created by yzjhh on 2019/5/17.
//

/**
 *
 * 127. Word Ladder
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 *
 * 题目描述：找出一条从 beginWord 到 endWord 的最短路径，每次移动规定为改变一个字符，并且改变之后的字符串必须在 wordList 中。

 Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
 * */
class Solution {
public:
    /*
    每个单词都当成一个节点，如果两个单词间只有一个字母不同，那么这两个节点之间有边相连
    问题转化成了，求两个节点间的最短路径
    */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.emplace_back(beginWord);
        int N = wordList.size();
        int start = N - 1;
        int end = 0;
        while(end < N && wordList[end] != endWord){
            ++end;
        }
        if(end == N){
            return 0;
        }
        vector<vector<int> > graphic = buildGraphic(wordList);
        return getMinLength(graphic, start, end);
    }

    bool isConnected(const string &s1, const string &s2){
        int diff_cnt = 0;
        for(int i = 0; i < s1.length() && diff_cnt <= 1; ++i){
            if(s1[i] != s2[i]){
                ++diff_cnt;
            }
        }
        return diff_cnt == 1;
    }

    vector<vector<int> > buildGraphic(const vector<string > &wordList){
        const int n = wordList.size();
        vector<vector<int> > graphic(n);
        for(int i = 0; i < n; ++i){
            for(int j = i; j < n; ++j){
                if(isConnected(wordList[i], wordList[j])){
                    graphic[i].emplace_back(j);
                    graphic[j].emplace_back(i);
                }
            }
        }
        return graphic;
    }

    int getMinLength(const vector<vector<int> > &graphic, int start, int end){
        const int n = graphic.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        int min_len = 1;
        while(!q.empty()){
            int q_size = q.size();
            ++min_len;
            while(q_size-- > 0){
                int cur = q.front();
                q.pop();
                for(auto next : graphic[cur]){
                    if(next == end){
                        return min_len;
                    }
                    if(visited[next]){
                        continue;
                    }
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
        return 0;
    }
};

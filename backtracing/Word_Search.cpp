//
// Created by julyjohn on 2019-04-07.
//
/**
 *
 * 79. Word Search
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 *
 * 题目描述：给定一个二维字符串矩阵，判断单词是否存在于该矩阵中
 *
 * note：回溯法，对于这种多层递归的问题，其中尤其要注意函数参数的传递方式，尽量使用引用传参
 *
Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(const vector<vector<char>> &board, const string &word, int i, int j, int cur_idx,
                vector<vector<bool>> &isVisited) {
        if (cur_idx == word.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || isVisited[i][j] ||
            word[cur_idx] != board[i][j]) {
            return false;
        }
        isVisited[i][j] = true;
        bool res = search(board, word, i + 1, j, cur_idx + 1, isVisited) ||
                   search(board, word, i - 1, j, cur_idx + 1, isVisited) ||
                   search(board, word, i, j + 1, cur_idx + 1, isVisited) ||
                   search(board, word, i, j - 1, cur_idx + 1, isVisited);
        isVisited[i][j] = false;
        return res;
    }

    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty() || board[0].empty()) {
            return false;
        }
        int r = board.size();
        int c = board[0].size();
        vector<vector<bool> > isVisited(r, vector<bool>(c, false));

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (search(board, word, i, j, 0, isVisited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {
            {'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'b'}
    };
    string word = "aaaaaaaaaaaaaaaaaaaa";;
    Solution *solution = new Solution();
    cout << solution->exist(board, word);
    return 0;
}
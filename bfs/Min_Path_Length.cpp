//
// Created by yzjhh on 2019/5/16.
//

/**
 *
 * 计算在网格中从两个点之间的最短路径长度
 *
 * 题目描述：1表示可以经过某个位置，求解从 (sr, sc) 位置到 (dr, dc) 位置的最短路径长度。
 *
 * */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minPathLength(const vector<vector<int> > grids, int sr, int sc, int dr, int dc) {
        if (grids.size() == 0 || grids[0].size() == 0) {
            return -1;
        }
        const vector<pair<int, int> > directions = {{0,  1},
                                                    {0,  -1},
                                                    {1,  0},
                                                    {-1, 0}};
        const int m = grids.size();
        const int n = grids[0].size();
        vector<vector<int> > visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = 1;
        int path_len = 0;
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i) {
                ++path_len;
                int cr = q.front().first;
                int cc = q.front().second;
                q.pop();
                for (pair<int, int> d : directions) {
                    int nr = cr + d.first;
                    int nc = cr + d.second;
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc]) {
                        continue;
                    }
                    if (nr == dr && nc == dc) {
                        return path_len;
                    }
                    q.push({nr, nc});
                    visited[nr][nc] = 1;
                }
            }
        }
        return -1;
    }
};

int main() {

}
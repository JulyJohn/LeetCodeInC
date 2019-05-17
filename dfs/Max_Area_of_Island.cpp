//
// Created by yzjhh on 2019/5/17.
//
/**
 *
 * 695. Max Area of Island
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
 * Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
 *
 * 题目描述：求最大连通区域的面积。

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
 * */
class Solution {
public:
    const vector<pair<int, int> > directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0){
            return 0;
        }
        int n = grid[0].size();
        int max_area = 0;
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int area = 0;
                dfs(grid, visited, i, j, area);
                max_area = max(max_area, area);
            }
        }
        return max_area;
    }

    void dfs(const vector<vector<int>>& grid, vector<vector<bool>> &visited, int i, int j, int &area){
        int m = grid.size();
        int n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0 ){
            return ;
        }
        ++area;
        visited[i][j] = true;
        for(auto d : directions){
            dfs(grid, visited, i + d.first, j + d.second, area);
        }
    }
};
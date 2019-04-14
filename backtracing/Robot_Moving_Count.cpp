//
// Created by yzjhh on 2019/4/14.
//
/**
 *
 * 机器人的运动范围
 *
 * 题目描述：地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
 * 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
 *
 * */

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        int cnt = 0;
        vector > visited(rows, vector(cols, false)); // 记录当前结点是否已经被访问过
        dfs_search(0, 0, threshold, visited, cnt, rows, cols);
        return cnt;
    }
    void dfs_search(int i, int j, int k, vector > &visited, int &cnt, int rows, int cols){
        // 首先i和j不能超出边界，其次如果当前结点访问过了就不用再继续搜索了，最后如果当前结点的“行列和”大于阈值那么也不用再继续搜索了
        if(i = rows || j = cols || visited[i][j] || getSumByRowCol(i, j) > k){ // 首先i和j不能超出边界，其次如果当前结点访问过了就不用再继续搜索了，最后如果当前结点的“行列和”大于阈值那么也不用再继续搜索了
            return ;
        }
        ++cnt;
        visited[i][j] = true;  // 记录当前结点已经被访问过
        // 分别向四个方向搜索
        dfs_search(i-1, j, k, visited, cnt, rows, cols);
        dfs_search(i+1, j, k, visited, cnt, rows, cols);
        dfs_search(i, j-1, k, visited, cnt, rows, cols);
        dfs_search(i, j+1, k, visited, cnt, rows, cols);
    }
    int getSumByRowCol(int row, int col){
        int res = 0;
        // sum row
        do{
            res += row % 10;
            row /= 10;
        }while(row != 0);
        // sum col
        do{
            res += col % 10;
            col /= 10;
        }while(col != 0);
        return res;
    }
};
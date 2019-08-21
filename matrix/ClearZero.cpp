//
// Created by yzjhh on 2019/8/21.
//
/**
 *
 * 清除行列
 * 题目描述 : 请编写一个算法，若N阶方阵中某个元素为0，则将其所在的行与列清零。
 *
 * 测试样例：[[1,2,3],[0,1,2],[0,0,1]]
 * 返回：[[0,0,3],[0,0,0],[0,0,0]]
 * */

class Clearer {
public:
    vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
        // write code here
        vector<bool> r_flag(n, false);
        vector<bool> c_flag(n, false);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(mat[i][j] == 0){
                    r_flag[i] = true;
                    c_flag[j] = true;
                }
            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(r_flag[i] || c_flag[j]){
                    mat[i][j] = 0;
                }
            }
        }
        return mat;
    }
};
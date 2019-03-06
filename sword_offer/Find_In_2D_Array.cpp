//
// Created by yzjhh on 2019/3/6.
//

/**
 * 4. 二维数组中的查找
 *
 * 题目描述: 给定一个二维数组，其每一行从左到右递增排序，从上到下也是递增排序。给定一个数，判断这个数是否在该二维数组中。
 *
 * */

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) { // 从左下角或者右上角开始找
        if(array.size() < 1){
            return false;
        }
        int r = array.size() - 1;
        int c = 0;
        while(r > -1 && c < array[0].size()){
            if(array[r][c] > target){
                r--;
            }else if(array[r][c] < target){
                c++;
            }else{
                return true;
            }
        }
        return false;
    }
};
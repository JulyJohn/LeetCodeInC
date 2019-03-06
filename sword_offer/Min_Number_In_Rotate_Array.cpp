//
// Created by yzjhh on 2019/3/6.
//

/**
 *
 * 11. 旋转数组的最小数字
 *
 * 题目描述：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
 * 例如数组 {3, 4, 5, 1, 2} 为 {1, 2, 3, 4, 5} 的一个旋转，该数组的最小值为 1。
 *
 * note: 旋转数组可以分为两部分分别有序的子数组，并且满足最后一个元素小于第一个元素（对递增数组）
 *
 * */

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int n = rotateArray.size();
        if(n == 0){
            return 0;
        }
        int lo = 0;
        int hi = n - 1;
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            if(rotateArray[lo] == rotateArray[mid] && rotateArray[hi] == rotateArray[mid]){ // 注意{1, 1, 0, 1}这种情况，就无法确定下一个解在哪个区间
                return findMin(rotateArray, lo, hi);
            }else if(rotateArray[hi] < rotateArray[mid]){
                lo = mid + 1;
            }else{
                hi = mid;
            }
        }
        return rotateArray[lo];
    }

    int findMin(vector<int> rotateArray, int lo, int hi){
        int min = rotateArray[lo];
        for(int i = lo + 1; i <= hi; ++i){
            if(rotateArray[i] < min){
                min = rotateArray[i];
            }
        }
        return min;
    }
};
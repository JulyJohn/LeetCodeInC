//
// Created by yzjhh on 2019/3/27.
//

/**
 *
 * 189. Rotate Array
 *
 * 循环左移问题的三种解法
 * */

class Solution {
public:

    // 方法二, space o(n); time o(1)
    // void rotate(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     if(n == 0){
    //         return;
    //     }
    //     vector<int> copy_nums(nums);
    //     for(int i = 0; i < n; ++i){
    //         nums[(i + k) % n] = copy_nums[i];
    //     }
    // }

//     // 方法一, 暴力，不通过
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         if(n == 0){
//             return;
//         }
//         for(int i = 0; i < k % n; ++i){
//             int tmp = nums[n-1];
//             for(int j = n-1; j > 0; --j){
//                 nums[j] = nums[j -1];
//             }
//             nums[0] = tmp;
//         }
//     }

    // 方法三,利用transpose((transpose(A)transpose(B))) = BA space o(1) time o(2n)
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0){
            return;
        }
        k = n - k % n;
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
        reverse(nums, 0, n-1);
    }

    void reverse(vector<int>& nums, int i, int j){
        while(i < j){
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            ++i;
            --j;
        }
    }
};
//
// Created by yzjhh on 2019/3/25.
//

/**
 *
 * 287. Find the Duplicate Number
 *
 * 题目描述：一个长度为 n + 1 的整形数组，其中的数字都在 1 到 n 之间，包括 1 和 n ，可知至少有一个重复的数字存在。假设只有一个数字重复，找出这个重复的数字。

要求：
不能更改数组内容（假设数组是只读的）。
只能使用恒定的额外空间，即要求空间复杂度是 O(1) 。
时间复杂度小于 O(n2)
数组中只有一个数字重复，但它可能不止一次重复出现。

 note：二分搜索+抽屉问题。确定一个中位数，扫描数组，计算数组中小于等于中位数的数字的个数，如果大于那么肯定在1到中位数中有重复，接下来就在该区间内找。
 * */

class Solution {
        public:
        int findDuplicate(vector<int>& nums) {
            int n = nums.size();
            if(n < 2){
                return -1;
            }
            int lo = 1;
            int hi = n - 1;

            while(lo < hi){
                int mid = lo + (hi - lo)/2;
                int cnt = 0;
                for(int num : nums){
                    if(num <= mid){
                        ++cnt;
                    }
                }
                if(cnt > mid){
                    hi = mid;
                }else{
                    lo = mid + 1;
                }
            }
            return lo;
        }
};
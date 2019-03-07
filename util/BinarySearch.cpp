//
// Created by yzjhh on 2019/3/7.
//

#include "BinarySearch.h"


namespace leetcode {

    /**
     *
     * 二分法的基本实现
     *
     * note：关于循环的终止条件要不要加等号，看lo或hi在循环体中有没有=mid的情况，如果有那肯定不能取等号，否则会陷入死循环
     * */
    int findIdx(vector<int> nums, int n, int target) {
        int lo = 0;
        int hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }

    /**
     *
     * 查找第一个大于等于某个元素的下标
     *
     * 分析：
     * 循环的终止条件lo=hi时，mid=lo，
     *      此时若nums[mid] < target，那么lo会加1，最后得到的也就是nums[lo] >= target
     *      反之若nums[mid] >= target，那么hi会减1，最后得到的可能是nums[hi] < target
     *      显然，符合要求的为lo
     * */
    int findFirstGreatOrEqualIdx(vector<int> nums, int n, int target) {
        int lo = 0;
        int hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return lo < n ? lo : -1;
//        return lo < n && nums[lo] == target ? lo : -1;  // 扩展，查找数组中某个数的最小位置的下标
//        return lo-1 >= 0 && nums[lo - 1] == target ? lo - 1 : -1;  // 扩展，查找数组中小于某个数的最大下标
    }

    /**
     *
     * 查找第一个大于某个元素的下标
     *
     * */
    int findFirstGreatIdx(vector<int> nums, int n, int target) {
        int lo = 0;
        int hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target) { // 对于num[mid] = target的情况，也给lo更新为mid+1，说明最后结果一定是大于target
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return lo < n ? lo : -1;
        return lo - 1 >= 0 && nums[lo - 1] == target ? lo - 1 : -1; //查找某个数位置的最大下标
    }

}
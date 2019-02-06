//
// Created by yzjhh on 2019/2/6.
//

/**
 * 88. Merge Sorted Array

 Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

 题目大意：给出两个排序好的数组nums1和nums2，将nums1和nums2合成一个排序好的数组

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
 * */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m - 1;
        int idx2 = n - 1;
        int idx = m + n - 1;
        while(idx2 >= 0){
            if(idx1 < 0){
                nums1[idx] = nums2[idx2--];
            }else if(nums1[idx1] < nums2[idx2]){
                nums1[idx] = nums2[idx2--];
            }else{
                nums1[idx] = nums1[idx1--];
            }
            idx--;
        }
    }

//    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
//        int i = 0;
//        int idx1 = 0;
//        int idx2 = 0;
//        while (idx1 < m && idx2 < n) {
//            if (nums1[i] > nums2[idx2]) {
//                for (int j = m + idx2; j > i; j--) {
//                    nums1[j] = nums1[j - 1];
//                }
//                nums1[i] = nums2[idx2];
//                idx2++;
//            } else {
//                idx1++;
//            }
//            i++;
//        }
//        if (idx2 < n) {
//            while (i < m + n) {
//                nums1[i] = nums2[idx2];
//                i++;
//                idx2++;
//            }
//        }
//    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
    int m = 0;
    int n = 1;
    solution->merge(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << ", ";
    }
}
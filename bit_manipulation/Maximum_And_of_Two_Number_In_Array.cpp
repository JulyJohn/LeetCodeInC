//
// Created by yzjhh on 2019/4/15.
//

/**
 *
 * 【腾讯】求数组中任意两个数的与值的最大值，要求时间复杂度为O(n)
 *
 * */
#include <iostream>
#include <vector>

using namespace std;

int find_maximum_and(vector<int> nums) {
    if (nums.size() < 2) {
        return 0;
    }
    vector<int> tmp_nums1;
    vector<int> tmp_nums2(nums);
    int res = 0;
    for (int i = 30; i >= 0; --i) { // 从最高位开始，依次判断每一位为1的数有哪些
        tmp_nums1.clear();
        for (int num : tmp_nums2) {
            if (num >> i & 1) {
                tmp_nums1.emplace_back(num);
            }
        }
        if (tmp_nums1.size() < 2) {
            continue;
        } else if (tmp_nums1.size() != tmp_nums2.size()) { // 将tmp_nums2中除了tmp_nums1的数都丢掉
            tmp_nums2.clear();
            tmp_nums2.assign(tmp_nums1.begin(), tmp_nums1.end());
        }
    }
    res = tmp_nums2[0] & tmp_nums2[1];
    return res;
}


int main() {
    vector<int> nums = {1, 2, 2, 3, 3};
    cout << find_maximum_and(nums) << endl;
    return 0;
}
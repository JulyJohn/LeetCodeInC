//
// Created by yzjhh on 2019/3/7.
//

#ifndef LEETCODEINCPLUS_BINARYSEARCH_H
#define LEETCODEINCPLUS_BINARYSEARCH_H


#include <string>
#include <vector>

namespace leetcode {
    using std::string;
    using std::vector;

    // 查找某个元素的下标
    int findIdx(vector<int> nums, int n, int target);
    // 查找第一个大于等于某个元素的下标
    int findFirstGreatOrEqualIdx(vector<int> nums, int n, int target);
    // 查找第一个大于某个元素的下标
    int findFirstGreatIdx(vector<int> nums, int n, int target);

}


#endif //LEETCODEINCPLUS_BINARYSEARCH_H

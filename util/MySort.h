//
// Created by yzjhh on 2019/2/18.
//

#ifndef LEETCODEINCPLUS_MYSORT_H
#define LEETCODEINCPLUS_MYSORT_H


#include <string>
#include <vector>
#include <iostream>

namespace leetcode {
    using std::string;
    using std::vector;

    void insertion_sort(vector<int> &a, int n);
    void selection_sort(vector<int> &a, int n);
    void bubble_sort(vector<int> &a, int n);
    void bubble_sort1(vector<int> &a, int n);
    void bubble_sort2(vector<int> &a, int n);
    void quick_sort(vector<int> &a, int n);
    void heap_sort(vector<int> &a, int n);
    void count_sort(vector<int> &a, int n);
    void bucket_sort(vector<int> &a, int n);
    void merge_sort(vector<int> &a, int n);
};


#endif //LEETCODEINCPLUS_MYSORT_H

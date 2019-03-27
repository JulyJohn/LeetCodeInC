//
// Created by yzjhh on 2019/3/27.
//

/**
 *
 * 56. Merge Intervals
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * 题目描述：给出一个区间集合，合并所有的重叠区间。
 *
 * note：
 * 1. 首先对区间按start排序
 * 2. 然后用一个vector来保存结果res，遍历数组，如果当前区间的start大于res的最后一个元素的end，那么直接加入res，否则弹出res最后一个元素，更新end结点，然后重新压入
 * 3. 更新end结点的时候要考虑到[1, 4][2, 3]这种后一个区间被前一个区间包括的情况
 *

 Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * */

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n < 2){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(),
             [](const Interval &itv1, const Interval &itv2) { return itv1.start < itv2.start; });
        vector<Interval> res;
        res.emplace_back(intervals[0]);
        Interval tmp_interval;
        for(int i = 1; i < n; ++i){
            tmp_interval = res.back();
            if(intervals[i].start > tmp_interval.end){
                res.emplace_back(intervals[i]);
            }else{
                tmp_interval.end = max(intervals[i].end, tmp_interval.end);
                res.pop_back();
                res.emplace_back(tmp_interval);
            }
        }
        return res;
    }
};
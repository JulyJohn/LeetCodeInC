//
// Created by yzjhh on 2019/2/25.
//

/**
 * 56. Merge Intervals
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * 題目描述： 给出一个区间的集合，合并所有的重叠区间。

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

 * */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}


};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() > 1) {
            sort(intervals.begin(), intervals.end(),
                 [](const Interval &itv1, const Interval &itv2) { return itv1.start < itv2.start; });
            Interval prev_itv;
            Interval cur_itv;
            vector<Interval>::iterator it = intervals.begin() + 1;
            while (it != intervals.end()) {
                prev_itv = *(it - 1);
                cur_itv = *it;
                if (cur_itv.start > prev_itv.end) {
                    it++;
                    continue;
                }
                if (cur_itv.end > prev_itv.end) {
                    intervals[it - intervals.begin() - 1].end = cur_itv.end;
                }
                intervals.erase(it);
            }
        }
        return intervals;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<Interval> intervals = {Interval(1, 2), Interval(2, 3), Interval(3, 4), Interval(1, 3)};
//    vector<Interval> intervals = {};
    vector<Interval> res = solution->merge(intervals);
    for (int i = 0; i < res.size(); ++i) {
        cout << "(" << res[i].start << ", " << res[i].end << "), ";
    }
}
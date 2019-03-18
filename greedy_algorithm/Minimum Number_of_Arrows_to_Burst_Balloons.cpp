//
// Created by yzjhh on 2019/3/18.
//

/**
 *
 * 452. Minimum Number of Arrows to Burst Balloons
 *
 * 题目描述：气球在一个水平数轴上摆放，可以重叠，飞镖垂直投向坐标轴，使得路径上的气球都会刺破。求解最小的投飞镖次数使所有气球都被刺破。
   note：也是计算不重叠的区间个数，不过和 Non-overlapping Intervals 的区别在于，[1, 2] 和 [2, 3] 在本题中算是重叠区间。
 *
 * */

class Solution {
public:
    // 实际上是no-overlapping问题，不同的是它要求不能接邻
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int n = points.size();
        if(n < 2){
            return n;
        }
        sort(points.begin(), points.end(), [](pair<int, int> p1, pair<int, int> p2){
            return p1.second < p2.second;
        });
        int end = points[0].second;
        int cnt = 1;
        for(int i = 1; i < n; ++i){
            if(points[i].first <= end){
                continue;
            }
            end = points[i].second;
            ++cnt;
        }
        return cnt;
    }
};
//
// Created by hejunhua on 18-11-27.
//
#include <iostream>
#include <vector>
#include <chrono>
#include <stack>
#include "../util/LeetcodeIO.h"

using namespace std;
using namespace chrono;
using namespace leetcode;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && nums[i] > q.back()) {
                q.pop_back();
            }
            q.push_back(nums[i]);
            const int s = i - k + 1; // s表示窗口的第一个元素的位置
            if (s < 0) {
                continue;
            }
            ans.push_back(q.front());
            if (nums[s] == q.front()){ // 当窗口一个元素的值等于队列的头时，说明队列的长度已经超出窗口的大小，此时应弹出最前面的元素
                q.pop_front();
            }
        }
        return ans;
    }

    vector<int> maxSlidingWindow_del(vector<int> &nums, int k) { // not solved.
        int n = nums.size();
        stack<pair<int, int>> s;
        int left[n];
        int right[n];
        int max[n];
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int len = 1;
            while (!s.empty() && s.top().first < nums[i]) {
                len += s.top().second;
                s.pop();
            }
            s.emplace(nums[i], len);
            left[i] = len;
        }

        while (!s.empty()) {
            s.pop();
        }
        for (int i = n - 1; i >= 0; --i) {
            int len = 1;
            while (!s.empty() && s.top().first <= nums[i]) {
                len += s.top().second;
                s.pop();
            }
            s.emplace(nums[i], len);
            right[i] = len;
        }

        for (int i = 0; i < n; ++i) {
            cout << left[i] << ", ";
        }
        cout << endl;
        for (int i = 0; i < n; ++i) {
            cout << right[i] << ", ";
        }
        cout << endl;
        for (int i = 0; i < n; ++i) {
            max[i] = left[i] + right[i] - 1;
            cout << max[i] << ", ";
        }
        cout << endl;
        return ans;
//        1, 2, 1, 1, 5, 1, 7, 8,
//        1, 3, 2, 1, 2, 1, 1, 1,
    }
};


int main() {
    vector<int> A;
    A = {1, 3, -1, -3, 5, 3, 6, 7};
//    string vec_file = "week2/large_vector_for_sosm.txt";
//    readVectorFromTxt(vec_file, A);
    int k = 3;

    Solution *s = new Solution();
    auto func_beg = system_clock::now();
    int loop_cnt = 1;
    vector<int> ans;
    for (int i = 0; i < loop_cnt; ++i) {
        ans = s->maxSlidingWindow(A, k);
    }
    auto func_end = system_clock::now();
    cout << "func_time: " << duration_cast<milliseconds>(func_end - func_beg).count() / loop_cnt << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ", ";
    }
    cout << endl << "hello world!~" << endl;
}
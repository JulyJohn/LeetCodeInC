//
// Created by yzjhh on 2019/4/9.
//
/**
 *
 * 数据流中的中位数
 *
 * 题目描述：如何得到一个数据流中的中位数？
 * 如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
 * 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
 * 我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
 *
 * note：维护两个堆，使得右边小顶堆的元素都大于左边大顶堆的元素，并且左边元素的个数，要么与右边相等（偶数次输入），要么比右边大1（奇数次输入）
 *
 * */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution2 {
private:
    vector<int> max_heap;
    vector<int> min_heap;

    void adjust_heap(vector<int> &nums, int lo, int hi, bool is_max) {
        for (int cur = lo, next = cur * 2 + 1; next <= hi; cur = next, next = cur * 2 + 1) {
            if (is_max) {
                if (next < hi && nums[next + 1] > nums[next]) {
                    ++next;
                }
                if (nums[next] > nums[cur]) {
                    swap(nums[next], nums[cur]);
                } else {
                    break;
                }
            } else {
                if (next < hi && nums[next + 1] < nums[next]) {
                    ++next;
                }
                if (nums[next] < nums[cur]) {
                    swap(nums[next], nums[cur]);
                } else {
                    break;
                }
            }
        }
    }

    void build_heap(vector<int> &heap, bool is_max) {
        int n = heap.size();
        for (int i = n / 2 - 1; i >= 0; --i) {
            adjust_heap(heap, i, n - 1, is_max);
        }
    }

    int pop(vector<int> &heap, bool is_max) {
        int ret = heap[0];
        heap.erase(heap.begin());
        build_heap(heap, is_max);
        return ret;
    }

    void push(vector<int> &heap, int num, bool is_max) {
        heap.emplace_back(num);
        build_heap(heap, is_max);
    }

public:
    void Insert(int num) {
        if (min_heap.empty() || num > min_heap[0]) {
            push(min_heap, num, false);
        } else {
            push(max_heap, num, true);
        }

        if (min_heap.size() == max_heap.size() + 2) {
            push(max_heap, pop(min_heap, false), true);
        }

        if (min_heap.size() + 1 == max_heap.size()) {
            push(min_heap, pop(max_heap, true), false);
        }
    }

    double GetMedian() {
        return min_heap.size() == max_heap.size() ? (min_heap[0] + max_heap[0]) / 2. : min_heap[0];
    }

};

class Solution {
public:
    void Insert(int num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }
        // 左边大顶堆的大小最多可以比右边小顶堆大1（奇数次输入）
        if (left.size() == right.size() + 2) {
            right.push(left.top());
            left.pop();
        }
        // 因为最后返回的只有可能是左边大顶堆的堆顶，所以右边小顶堆的大小不能比左边小顶堆大
        if (left.size() + 1 == right.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double GetMedian() {
        return left.size() == right.size() ? (left.top() + right.top()) / 2. : left.top();
    }

private:
    // 右边小顶堆的元素都大于左边大顶堆的元素，并且左边元素的个数，要么与右边相等（偶数次输入），要么比右边大1（奇数次输入）
    priority_queue<int, vector<int>, less<int> > left; // 大顶堆
    priority_queue<int, vector<int>, greater<int> > right; // 小顶堆
};

int main() {
    Solution2 *solution2 = new Solution2();
    Solution *solution = new Solution();
    vector<int> nums = {1, 2, 3, 4, 4, 2, 5, 1, 2, 3, 4, 4, 2, 5};
    for (int i = 0; i < nums.size(); ++i) {
        solution2->Insert(nums[i]);
        solution->Insert(nums[i]);
        cout << solution2->GetMedian() << ", ";
        cout << solution->GetMedian() << endl;
    }
    return 0;
}
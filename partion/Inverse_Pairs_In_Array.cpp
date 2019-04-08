//
// Created by yzjhh on 2019/4/4.
//
/**
 *
 * 数组中的逆序对
 *
 * 题目描述：在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
 *
 * note：实际上可以看作稳定排序方法中，元素发生交换的次数
 *
 * */

#include <iostream>
#include <vector>

using namespace std;
//#define BUBBLESORT
#define MERGESORT

#ifdef MERGESORT

class Solution {
public:
    int InversePairs(vector<int> data) {
        long cnt = 0;
        vector<int> tmp(data);
        mergeSort(data, tmp, 0, data.size() - 1, cnt);
        return (int) cnt % 1000000007;
    }

    void mergeSort(vector<int> &data, vector<int> &tmp, int lo, int hi, long &cnt) {
        if (lo >= hi) {
            return;
        }
        int mid = lo + (hi - lo) / 2;
        mergeSort(data, tmp, lo, mid, cnt);
        mergeSort(data, tmp, mid + 1, hi, cnt);
        merge(data, tmp, lo, mid, hi, cnt);
    }

    void merge(vector<int> &data, vector<int> &tmp, int lo, int mid, int hi, long &cnt) {
        for (int k = lo; k <= hi; ++k) {
            tmp[k] = data[k];
        }
        int i = lo;
        int j = mid + 1;
        for (int k = lo; k <= hi; ++k) {
            if (i > mid) {
                data[k] = tmp[j++];
            } else if (j > hi) {
                data[k] = tmp[i++];
            } else if (tmp[i] > tmp[j]) {
                cnt += mid - i + 1; // i~mid是有序的，所以如果tmp[i] > tmp[j] 那么{tmp[i]~tmp[mid]} > tmp[i]
                data[k] = tmp[j++];
            } else {
                data[k] = tmp[i++];
            }
        }
    }
};

#endif


#ifdef BUBBLESORT
class Solution {
public:

    int InversePairs(vector<int> data) {
        long cnt = 0;
        bubbleSort(data, cnt);
        return (int)cnt%1000000007;
    }

    // 冒泡排序的方法
    void bubbleSort(vector<int> data, long &cnt) {
        int n = data.size();
        int end_idx = n - 1;
        for (int i = 1; i < n; ++i) {
            bool is_changed = false;
            int tmp_end_idx = 0;
            for (int j = 0; j < end_idx; ++j) {
                if (data[j] > data[j + 1]) {
                    swap(data[j], data[j + 1]);
                    ++cnt;
                    tmp_end_idx = j + 1;
                    is_changed = true;
                }
            }
            end_idx = tmp_end_idx;
            if (!is_changed) {
                break;
            }
        }
    }
};
#endif

int main() {
    vector<int> data = {1, 2, 3, 4, 5, 6, 7, 0};
    Solution *solution = new Solution();
    cout << solution->InversePairs(data);
    return 0;
}
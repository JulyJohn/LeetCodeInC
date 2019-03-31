//
// Created by yzjhh on 2018/10/24.
//

/**
 * 896. Monotonic Array
 *
 * An array is monotonic if it is either monotone increasing or monotone decreasing.
 * An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].
 * Return true if and only if the given array A is monotonic.
 *
 * 大意：判断一个数组是否单调
 *
 * Note:
 *      1 <= A.length <= 50000
 *      -100000 <= A[i] <= 100000
 * */
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

class Solution {
public:
    bool isMonotonic_usual(vector<int> &A) {
        bool de = false, in = false;
        for (int i = 0; i < A.size() - 1; i++) {
            if (A[i] < A[i + 1])
                in = true;
            else if (A[i] > A[i + 1])
                de = true;
        }
        if (in && de)
            return false;
        return true;
    }

    bool isMonotonic(vector<int> &A) {
        int A_length = A.size();
        if (A_length < 3) {
            return true;
        }
        int start_idx = 1;
        for (; start_idx < A_length; ++start_idx) {
            if (A[start_idx] == A[start_idx - 1]) {
                continue;
            } else {
                break;
            }
        }
        bool is_increase = A[start_idx] > A[start_idx - 1];
        if (is_increase) {
            for (int i = start_idx + 1; i < A_length; ++i) {
                if (A[i] < A[i - 1]) {
                    return false;
                }
            }
        } else {
            for (int i = start_idx + 1; i < A_length; ++i) {
                if (A[i] > A[i - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {

    Solution *s = new Solution();
    vector<int> A;
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(2);
//    A.push_back(1);
//    A.push_back(2);

    auto func_beg = system_clock::now();
    int loop_num = 100000;
    for (int i = 0; i < loop_num; ++i) {
        s->isMonotonic(A);
    }
    auto func_duration = duration_cast<milliseconds>(system_clock::now() - func_beg);
    cout << "func_duaration: " << func_duration.count() << endl;

    bool result = s->isMonotonic(A);
    cout << result << endl;
    return 0;
}
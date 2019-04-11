//
// Created by yzjhh on 2019/4/11.
//

/**
 *
 * 数组中超过一半的元素的个数
 *
 * note：

参考多数投票算法的思想

先随意确定一个候选元素，cnt是候选元素的计数，当遇到一个跟候选元素不同的元素时，两者数量上抵消一个，cnt减1。一旦cnt变成0，就重新找一个候选元素。
当遇到一个与候选元素不同的元素时，就要抵消。
对于候选元素和当前元素，可能存在两种情况：

两者中有一个正好是主要元素；
两者都不是主要元素。
对于情况1，抵消过后，主要元素还是主要元素；对于情况2，可以说主要的元素的地位得到了巩固。所以算法最终能找到主要元素。
 * */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        if (n == 0) {
            return 0;
        }
        quickSortIn3Way(numbers, 0, n - 1);

        int mid_idx = n / 2;
        int mid_val = numbers[mid_idx];
        int cnt = 0;
        int i = mid_idx, j = mid_idx;
        while (i >= 0 && j < n) {
            if (numbers[i] != mid_val && numbers[j] != mid_val) {
                break;
            }
            if (numbers[i] == mid_val) {
                --i;
            }
            if (numbers[j] == mid_val) {
                ++j;
            }
        }
        return j - i + 1 - (numbers[i] != mid_val) - (numbers[j] != mid_val) > mid_idx ? mid_val : 0;
//        int mid_idx = n / 2;
//        int cnt = 0;
//        for (int i = 0; i < n; ++i) {
//            if (numbers[i] == numbers[mid_idx]) {
//                ++cnt;
//                if (cnt > mid_idx) {
//                    return numbers[mid_idx];
//                }
//            }
//            if (cnt + (n - i - 1) <= mid_idx) {
//                return 0;
//            }
//        }
//        return numbers[mid_idx];
    }

    void quickSortIn3Way(vector<int> &a, int lo, int hi) {
        if (lo >= hi) {
            return;
        }
        int i = lo + 1;
        int lt = lo;
        int gt = hi;
        int base = a[lo];
        while (i <= gt) {
            if (a[i] < base) {
                swap(a[lt++], a[i++]);
            } else if (a[i] > base) {
                swap(a[i], a[gt--]);
            } else {
                ++i;
            }
        }
        quickSortIn3Way(a, lo, lt - 1);
        quickSortIn3Way(a, gt + 1, hi);
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> numbers = {2, 2, 2, 2, 1, 1, 1, 1};
    cout << solution->MoreThanHalfNum_Solution(numbers);
    return 0;
}
//
// Created by hejunhua on 19-1-18.
//

/**
 *
 * 900. RLE Iterator
Write an iterator that iterates through a run-length encoded sequence.

The iterator is initialized by RLEIterator(int[] A), where A is a run-length encoding of some sequence.  More specifically, for all even i, A[i] tells us the number of times that the non-negative integer value A[i+1] is repeated in the sequence.

The iterator supports one function: next(int n), which exhausts the next n elements (n >= 1) and returns the last element exhausted in this way.  If there is no element left to exhaust, next returns -1 instead.

For example, we start with A = [3,8,0,9,2,5], which is a run-length encoding of the sequence [8,8,8,5,5].  This is because the sequence can be read as "three eights, zero nines, two fives".

 题目大意：
 模拟一个迭代器．

 该迭代器由RLE迭代器(int[] A)初始化，其中A中的奇数位表示偶数位数字要重复出现的次数．
 例如对A = [3,8,0,9,2,5]，对应的序列为[8,8,8,5,5]

 该迭代器支持一个函数：next(int n)，它将删除接下来的n个元素，并返回最后一个删除的数，如果最后一个删除的数不存在，则返回-1．

Example 1:

Input: ["RLEIterator","next","next","next","next"], [[[3,8,0,9,2,5],2,1,1,2]]
Output: [null,8,8,5,-1]
Explanation:
RLEIterator is initialized with RLEIterator([3,8,0,9,2,5]).
This maps to the sequence [8,8,8,5,5].
RLEIterator.next is then called 4 times:

.next(2) exhausts 2 terms of the sequence, returning 8.  The remaining sequence is now [8, 5, 5].

.next(1) exhausts 1 term of the sequence, returning 8.  The remaining sequence is now [5, 5].

.next(1) exhausts 1 term of the sequence, returning 5.  The remaining sequence is now [5].

.next(2) exhausts 2 terms, returning -1.  This is because the first term exhausted was 5,
but the second term did not exist.  Since the last term exhausted does not exist, we return -1.

Note:

0 <= A.length <= 1000
A.length is an even integer.
0 <= A[i] <= 10^9
There are at most 1000 calls to RLEIterator.next(int n) per test case.
Each call to RLEIterator.next(int n) will have 1 <= n <= 10^9.
 * */
#include <iostream>
#include <vector>

using namespace std;

class RLEIterator {
private:
    int cur_idx;
    vector<int> init_vec;

public:

    RLEIterator(vector<int> A) {
        this->cur_idx = 0;
        this->init_vec = A;
    }

    int next1(int n) {
        while (this->cur_idx < this->init_vec.size() && n > this->init_vec[this->cur_idx]) {
            n -= this->init_vec[this->cur_idx];
            this->cur_idx += 2;
        }
        if (this->cur_idx == this->init_vec.size()) {
            return -1;
        }
        this->init_vec[this->cur_idx] -= n;
        return this->init_vec[this->cur_idx + 1];
    }

    int next(int n) {
        while (n > 0) {
            if (n > this->init_vec[this->cur_idx]) { //大于当前个数，减去当前个数，往前跳一个
                n = n - this->init_vec[this->cur_idx];
                this->cur_idx += 2;
                if (this->cur_idx == this->init_vec.size()) { //表示溢出了
                    return -1;
                }
            } else { //小于当前个数，从当前个数中减去n个，返回当前数值
                this->init_vec[this->cur_idx] -= n;
                break;
            }
        }
        if (this->cur_idx < this->init_vec.size()) { //表示溢出了
            return this->init_vec[this->cur_idx + 1];
        } else {
            return -1;

        }
    }
};

int main() {
//    vector<int> next_arr = {2, 1, 1, 2};
//    vector<int> init_vec = {3, 8, 0, 9, 2, 5};

    vector<int> next_arr = {5039, 62, 3640, 671, 67, 395, 262, 839, 74, 43, 42, 77, 13, 6, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    vector<int> init_vec = {635, 606, 576, 391, 370, 981, 36, 21, 961, 185, 124, 210, 801, 937, 22, 426, 101, 260, 221,
                            647, 350, 180, 504, 39, 101, 989, 199, 358, 732, 839, 919, 169, 673, 967, 58, 676, 846, 342,
                            250, 597, 442, 174, 472, 410, 569, 509, 311, 357, 838, 251};
    RLEIterator *rle_iterator = new RLEIterator(init_vec);
    for (int i = 0; i < next_arr.size(); i++) {
        cout << rle_iterator->next(next_arr[i]) << " ";
    }
//    cout << rle_iterator->next(2) << " ";
//    cout << rle_iterator->next(1) << " ";
//    cout << rle_iterator->next(1) << " ";
//    cout << rle_iterator->next(2) << " ";
}
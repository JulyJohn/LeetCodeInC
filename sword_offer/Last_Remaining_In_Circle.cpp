//
// Created by yzjhh on 2019/4/3.
//

/**
 *
 * 圆圈中最后剩下的数
 *
 * 题目描述：有n个小朋友编号为0~n-1围成一圈，从第0个小朋友开始报数，报到第m个小朋友的时候，该小朋友退出，从他的下一个接着往下报，每到第m个，第m个就退出围圈，求最后剩下的小朋友的编号
 *
 * */
#include <iostream>
#include <list>

using namespace std;


class Solution {
public:

    // 当前的结果是上一次结果的基础上加m，由于是环，因此还要对N取余
    int LastRemaining_Solution(int n, int m) {
        if (n == 0) {
            return -1;
        }
        if (n == 1) {
            return 0;
        }
        return (LastRemaining_Solution(n - 1, m) + m) % n;
    }

    // 链表模拟
    int LastRemaining_Solution1(int n, int m) {
        if (n == 0) {
            return -1;
        }
        list<int> people;
        for (int i = 0; i < n; ++i) {
            people.push_back(i);
        }
        list<int>::iterator it_last = people.begin();
        list<int>::iterator it = it_last;
        list<int>::iterator tmp_it;
        while (people.size() > 1) {
            int cnt = m;
            it = it_last;
            while (--cnt != 0) {
                ++it;
                if (it == people.end()) {
                    it = people.begin();
                }
            }
            tmp_it = it;
            it_last = ++it == people.end() ? people.begin() : it;
            people.erase(tmp_it);
        }
        return *it_last;
    }
};

int main() {
    Solution *solution = new Solution();
    cout << solution->LastRemaining_Solution(5, 3);
    return 0;
}
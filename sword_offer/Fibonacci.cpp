//
// Created by yzjhh on 2019/3/6.
//

/**
 *
 * 10.1 斐波那契数列
 *
 * 题目描述：f(n) = f(n - 1) + f(n - 2)
 *
 * */
#include <iostream>
#include <unordered_map>

using namespace std;

static int compute_cnt = 0;

class Solution {
private:
    unordered_map<int, int> mem;
public:
    int Fibonacci(int n) {
        compute_cnt++;
        if (n < 2) {
            return n;
        }
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }

    // 用一个map来存储已经计算过的数
    int Fibonacci2(int n) {
        compute_cnt++;
        if (n < 2) {
            return n;
        }
        int val1;
        int val2;
        if (mem.find(n - 1) == mem.end()) {
            val1 = Fibonacci2(n - 1);
            mem.emplace(n - 1, val1);
        } else {
            val1 = mem[n - 1];
        }

        if (mem.find(n - 2) == mem.end()) {
            val2 = Fibonacci2(n - 2);
            mem.emplace(n - 2, val2);
        } else {
            val2 = mem[n - 2];
        }

        return val1 + val2;
    }

    // 动态规划
};

int main() {
    Solution *solution = new Solution();
    cout << solution->Fibonacci(10) << endl;
    cout << compute_cnt;
    return 0;
}
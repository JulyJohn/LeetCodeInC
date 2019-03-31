//
// Created by yzjhh on 2019/3/12.
//

/**
 *
 * 题目描述： 给你n对括号，找出所有的匹配方式
 *
 * note:
 * 假设某一个状态时，左边括号的数量为l，右边括号的数量为r，
 * 那么对于一个合法的匹配，必定有：l >= r
 * 存在如下几种情况：
 * 1. r = n, 此时说明所有的n对括号都用完了，打印出此时的str, num++
 * 2. l = r, 那么下一个符号必定是'('，那么给str加上'(',同时l++
 * 3. l > r:
 *  3.1 l = n, 此时'('用完了，接下来只可能是')'，str加上')'，同时r++
 *  3.2 l < n, 那么下一个符号存在两种情况，'('或')'，
 *             对于'('，l++，调用递归，
 *             然后再考虑')'，这里的做法是先把之前str中的'('删除，然后再将')'放入，r++，调用递归
 *
 *
 *
 * */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void printMatchKuohao(int l, int r, int n, string str, int &cnt) {
        if (r == n) {
            ++cnt;
            cout << str << endl;
            return;
        } else if (l == r) {
            str.append("(");
            ++l;
            printMatchKuohao(l, r, n, str, cnt);
        } else {
            if (l == n) {
                str.append(")");
                ++r;
                printMatchKuohao(l, r, n, str, cnt);
            } else {
                str.append("(");
                ++l;
                printMatchKuohao(l, r, n, str, cnt);
                str.pop_back();
                --l;
                str.append(")");
                ++r;
                printMatchKuohao(l, r, n, str, cnt);
            }
        }
        return;
    }
};

int main() {
    Solution *solution = new Solution();
    string str = "";
    int cnt = 0;
    int n = 3;
    solution->printMatchKuohao(0, 0, n, str, cnt);
    cout << cnt;
    return 0;
}
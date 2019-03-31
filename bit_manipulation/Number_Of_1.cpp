//
// Created by yzjhh on 2019/3/30.
//

/**
 *
 * 二进制数中1的个数
 * */
#include <iostream>

using namespace std;

int NumberOf1(int n) {
    int cnt = 0;
    while (n != 0) {
        ++cnt;
        n &= (n - 1);
    }
    return cnt;
}


int main() {
    int input;
    cin >> input;
    cout << NumberOf1(input);
}
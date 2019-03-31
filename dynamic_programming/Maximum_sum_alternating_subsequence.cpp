//
// Created by yzjhh on 2019/3/28.
//

/**
 *
 * 最大交替子序列和
 *
 * */

#include<bits/stdc++.h>

using namespace std;

int maxSum(vector<int > &nums, int n) {
    if (n == 1)
        return nums[0];

    vector<int > down(n, 0); // 以nums[i]结尾并且nums[i]比前一数字小的最大和

    vector<int > up(n, 0); // 以nums[i]结尾并且nums[i]比前一数字大的最大和

    down[0] = nums[0];
    up[0] = nums[0];

    int flag = 0; // 标识第一个递减的找到了

    // 遍历
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[i]) {
                down[i] = max(down[i], up[j] + nums[i]);
                flag = 1;
            } else if (nums[j] < nums[i] && flag == 1)
                up[i] = max(up[i], down[j] + nums[i]);
        }
    }

    // 找最大值
    int res = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (res < up[i])
            res = up[i];
        if (res < down[i])
            res = down[i];
    }

    return res;
}

//Driver program
int main() {
    vector<int > arr = {8, 2, 3, 5, 7, 9, 10};
    int n = arr.size();
    cout << "Maximum sum = "
         << maxSum(arr, n) << endl;
    return 0;
}

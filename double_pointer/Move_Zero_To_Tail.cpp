//
// Created by yzjhh on 2019/3/14.
//

/**
 *
 * 将数组中的0移到末尾
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveToTail(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) {
            return;
        }
        int i = 0;
        for(int j = 0; j < n; ++j){
            if(arr[j] != 0){
                arr[i++] = arr[j];
            }
        }
        while(i<n){
            arr[i++] = 0;
        }
    }
};

int main() {
    vector<int> arr = {0, 1, 0, 3, 12};
    Solution *solution = new Solution();
    solution->moveToTail(arr);
    return 0;
}
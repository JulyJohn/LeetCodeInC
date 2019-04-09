//
// Created by yzjhh on 2019/4/9.
//

/**
 *
 * 把数组排成最小的数
 *
 * 题目描述；输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
 *
 * note: 实际上可以看作是一个排序问题，其中a>b的条件是str(a)+str(b) > str(b)+str(a)
 *
 * */

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        quickSort(numbers, 0, numbers.size()-1);
        string res = "";
        for(int a : numbers){
            res += to_string(a);
        }
        return res;
    }

    void quickSort(vector<int > &a, int lo, int hi){
        if(lo >= hi){
            return;
        }
        int base = a[lo];
        int lt = lo;
        int gt = hi + 1;
        while(1){
            while(myGtComparator(base, a[++lt])){
                if(lt == hi){
                    break;
                }
            }
            while(myGtComparator(a[--gt], base)){
                if(gt == lo){
                    break;
                }
            }
            if(lt >= gt){
                break;
            }
            swap(a[lt], a[gt]);
        }
        swap(a[lo], a[gt]);
        quickSort(a, lo, gt - 1);
        quickSort(a, gt + 1, hi);
    }

    bool myGtComparator(int a, int b){
        string str_a = to_string(a);
        string str_b = to_string(b);
        return str_a + str_b > str_b + str_a;
    }
};

int main() {
    vector<int> numbers = {3, 32, 321};
    Solution *solution = new Solution();
    cout << solution->PrintMinNumber(numbers);
    return 0;
}
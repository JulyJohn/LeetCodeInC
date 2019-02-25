//
// Created by yzjhh on 2018/10/25.
//

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include "util/MySort.h"

using namespace std;
using namespace chrono;
using namespace leetcode;

class Solution {
public:
    bool helloworld(string s) {
        cout << s << endl;
    }

    int test_sort(string sort_name, vector<int> arr_src) {
        int n = arr_src.size();

        vector<int> arr_my(arr_src);

        vector<int> arr_std(arr_my);
        sort(arr_std.begin(), arr_std.end());

        if (sort_name.compare("insertion_sort") == 0) {
            insertion_sort(arr_my, n);
        } else if (sort_name.compare("selection_sort") == 0) {
            selection_sort(arr_my, n);
        } else if (sort_name.compare("bubble_sort") == 0) {
            bubble_sort(arr_my, n);
        } else if (sort_name.compare("bubble_sort1") == 0) {
            bubble_sort1(arr_my, n);
        } else if (sort_name.compare("bubble_sort2") == 0) {
            bubble_sort2(arr_my, n);
        } else if (sort_name.compare("quick_sort") == 0) {
            quick_sort(arr_my, n);
        } else if (sort_name.compare("heap_sort") == 0) {
            heap_sort(arr_my, n);
        }else if (sort_name.compare("count_sort") == 0) {
            count_sort(arr_my, n);
        }else if (sort_name.compare("bucket_sort") == 0) {
            bucket_sort(arr_my, n);
        }else if (sort_name.compare("merge_sort") == 0) {
            merge_sort(arr_my, n);
        }

        int preview_range = 10; // 预览条数
        for (int i = 0; i < n; ++i) {
            if (arr_my[i] != arr_std[i]) {
                cout << endl << "idx->" << i << " erro! " << arr_my[i] << " : " << arr_std[i] << endl;
                cout << "input: " << endl;
                for (int j = 0; j < n; ++j) {
                    cout << arr_src[j] << ", ";
                }
                cout << endl << "std result: " << endl;
                for (int j = 0; j < n; ++j) {
                    cout << arr_std[j] << ", ";
                }
                cout << endl << "my result: " << endl;
                for (int j = 0; j < n; ++j) {
                    cout << arr_my[j] << ", ";
                }
                return -1;
            }
            if (n > preview_range * 2 && (i < n - 20 && i > 19)) {
                if (i == 20) {
                    cout << "...,";
                }
                continue;
            } else {
                cout << arr_my[i] << ",";
            }
        }
        cout << endl;
        return 0;
    }
};

int main() {

    Solution *s = new Solution();

    auto func_beg = system_clock::now();
    long loop_num = 100;
    for (int i = 0; i < loop_num; ++i) {
//        s->helloworld("I love you~");
        int n = i;
        vector<int> arr_src;
        srand((unsigned) time(0) + i);
        for (int j = 0; j < n; ++j) {
            arr_src.push_back(rand() % 100 + 1);
        }
        string sort_style = "merge_sort";
        int flag = s->test_sort(sort_style, arr_src);
        if (flag == -1) {
            cout << endl << "error occur!" << endl;
            return -1;
        }
    }
    auto func_duration = duration_cast<milliseconds>(system_clock::now() - func_beg);
//    cout << "func_duaration: " << func_duration.count() << endl;
}
//
// Created by julyjohn on 2019-03-31.
//

/**
 *
 * 字符串中第一次出现的字符
 *
 * note：bitmap
 * */
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int* bitmap = new int[16]();
        int arr_idx, bit_idx;
        for(int i = 0; i < str.length(); ++i){
            arr_idx = str[i] * 2 / 32;
            bit_idx = str[i] * 2 % 32;
            if(((bitmap[arr_idx] >> bit_idx) & 1) == 0){
                bitmap[arr_idx] |= (1 << bit_idx);
            }else if(((bitmap[arr_idx] >> (bit_idx+1)) & 1) == 0){
                bitmap[arr_idx] |= (1 << (bit_idx+1));
            }
        }
        for(int i = 0; i < str.length(); ++i){
            arr_idx = str[i] * 2 / 32;
            bit_idx = str[i] * 2 % 32;
            if(((bitmap[arr_idx] >> bit_idx) & 1) == 1 && ((bitmap[arr_idx] >> (bit_idx+1)) & 1) == 0){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution *solution = new Solution();
    string str = "google";
    solution->FirstNotRepeatingChar(str);
    return 0;
}
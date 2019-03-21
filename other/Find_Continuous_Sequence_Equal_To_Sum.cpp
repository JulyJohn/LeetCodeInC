//
// Created by yzjhh on 2019/3/21.
//

/**
 *
 * 和为S的连续正数序列
 *
 * 题目描述：找出所有和为S的连续正数序列，输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
 *
 * */


class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        int start = 1;
        int end = 2;
        int cur_sum = 3;
        while(end < sum){ // end必须小于sum
            if(cur_sum < sum){ // 如果小于，那么start不动，end往后移
                ++end;
                cur_sum += end;
            }else if(cur_sum > sum){ // 如果大于，那么end不动，start前移
                cur_sum -= start;
                ++start;
            }else{ // 如果等于，那么整个窗口往后移动一位
                vector<int > tmp_res(end-start+1);
                for(int i = start; i <= end; ++i){
                    tmp_res[i-start] = i;
                }
                res.push_back(tmp_res);
                cur_sum -= start;
                ++start;
                ++end;
                cur_sum += end;
            }
        }
        return res;
    }
};
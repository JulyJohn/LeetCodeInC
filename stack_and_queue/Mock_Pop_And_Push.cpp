//
// Created by yzjhh on 2019/4/10.
//

/**
 *
 * 判断出栈顺序是否合法
 *
 * note：用一个栈来模拟弹入和弹出操作
 *
 * */

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int n = pushV.size();
        if(n != popV.size()){
            return false;
        }
        if(n == 0){
            return true;
        }
        stack<int > mock_s;
        int push_idx = 0;
        int pop_idx = 0;
        while(push_idx < n){
            mock_s.push(pushV[push_idx]);
            while(pop_idx < n && !mock_s.empty() && popV[pop_idx] == mock_s.top()){
                mock_s.pop();
                ++pop_idx;
            }
            ++push_idx;
        }
        return mock_s.empty();
    }
};
//
// Created by yzjhh on 2019/4/3.
//

/**
 *
 * 扑克牌顺子
 *
 * 题目描述：一副牌有4个大小王，它们可以替换成任意的牌面。现在抽五张牌，判断他们能不能组成一个顺子。
 *
 * */

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int n = numbers.size();
        if(n < 5){
            return false;
        }
        sort(numbers.begin(), numbers.end());
        // 统计癞子的数量
        int lz_cnt = 0;
        for(int i = 0; i < n; ++i){
            if(numbers[i] == 0){
                ++lz_cnt;
            }else{
                break;
            }
        }

        // 用癞子去填补空缺
        for(int i = lz_cnt; i < n-1; ++i){
            // 如果有相同的牌，则肯定不是顺子
            if(numbers[i+1] == numbers[i]){
                return false;
            }
            lz_cnt -= numbers[i+1] - numbers[i] - 1;
        }
        return lz_cnt >= 0;
    }
};
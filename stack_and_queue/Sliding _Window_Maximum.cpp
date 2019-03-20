//
// Created by yzjhh on 2019/3/20.
//

/**
 *
 * 239. Sliding Window Maximum
 *
 * 题目描述： 大小为k的窗口在数组中滑动，找到每个滑窗的最大值
 *
 * note：碰到一个元素如果比队尾元素大，那么就把队尾元素弹出，这样维持一个递增双端队列，
 *      那么队首元素一直是最大的，但是每次都要检查队首元素是否已经过界，
 *      即 head_idx + size <= i，如果过界，那就把队首元素弹出。
 * */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        int n = nums.size();
        if(k > n || n < 1 || k < 1){
            return res;
        }
        for(int i = 0; i < k; ++i){
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(int i = k; i < n; ++i){
            res.push_back(nums[dq.front()]);
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        return res;
    }
};
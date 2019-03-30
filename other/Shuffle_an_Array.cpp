//
// Created by julyjohn on 2019-03-31.
//

/**
 *
 * ·
 *
 * https://en.wikipedia.org/wiki/Fisher–Yates_shuffle
 * */

class Solution {
private:
    vector<int > v;
public:
    Solution(vector<int> nums) : v(nums){

    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return v;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int > sf_nums(v);
        for(int i = 0; i < sf_nums.size(); ++i){
            int r = i + rand() % (sf_nums.size() - i);
            int tmp = sf_nums[r];
            sf_nums[r] = sf_nums[i];
            sf_nums[i] = tmp;
        }
        return sf_nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
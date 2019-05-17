//
// Created by yzjhh on 2019/5/17.
//

/**
 *
 * 787. Cheapest Flights Within K Stops
 *
 * 题目描述：给出航班路线表，[src, dst, price]，找到两地间最便宜的航班路线。
 *
 * */

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int, int> > > f_table;
        for(auto flight : flights){
            f_table[flight[0]].emplace_back(flight[1], flight[2]);
        }
        queue<pair<int, int> > q;
        q.push({src, 0});
        int stop = 0;
        int min_fee = INT_MAX;
        bool has_path = false;
        while(!q.empty()){
            int size = q.size();
            while(size-- > 0){
                int cur_fIdx = q.front().first;
                int cur_fee = q.front().second;
                q.pop();
                if(cur_fIdx == dst){
                    has_path = true;
                    min_fee = min(cur_fee, min_fee);
                }
                for(auto next_f : f_table[cur_fIdx]){
                    int next_fIdx = next_f.first;
                    int next_fee = next_f.second;
                    if(cur_fee + next_fee > min_fee){
                        continue;
                    }
                    q.push({next_fIdx, cur_fee + next_fee});
                }
            }
            if(stop++ > K){
                break;
            }
        }
        return has_path ? min_fee : -1;
    }
};
//
// Created by yzjhh on 2019/5/17.
//

/**
 *
 * 279. Perfect Squares
 *
 * Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * 题目描述：找到一个数可以由完美平方数
 *
 * note：把每一个整数看作一个节点，如果两个数的差是平方数，那么这两个节点之间有边。
 *      目标就是要找出两个节点间的最短路径。
 *
 * */

class Solution {
public:
    int numSquares(int n) {
        // generate squares
        vector<int > squares_list;
        for(int i = 1; i * i <= n; ++i){
            squares_list.emplace_back(i * i);
        }
        vector<bool > visited(n+1, false);
        queue<int > q;
        q.push(n);
        visited[n] = true; // 后访问到的所经历的步数一定更多，所以就不用再遍历下去了
        int level = 0;
        while(!q.empty()){
            ++level;
            int q_size = q.size();
            while(q_size-- > 0){
                int cur = q.front();
                q.pop();
                for(int s : squares_list){
                    int next = cur - s;
                    if(next < 0){
                        break;
                    }
                    if(next == 0){
                        return level;
                    }
                    if(visited[next]){
                        continue;
                    }
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        return n;
    }
};
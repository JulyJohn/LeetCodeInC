//
// Created by yzjhh on 2019/2/24.
//

/**
 *
 * 455. Assign Cookies
 *
 * Assume you are an awesome parent and want to give your children some cookies.
 * But, you should give each child at most one cookie.
 * Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with;
 * and each cookie j has a size sj. If sj >= gi, we can assign the cookie j to the child i, and the child i will be content.
 * Your goal is to maximize the number of your content children and output the maximum number.

 题目描述：每个孩子都有一个满足度，每个饼干都有一个大小，只有饼干的大小大于等于一个孩子的满足度，该孩子才会获得满足。求解最多可以获得满足的孩子数量。

给一个孩子的饼干应当尽量小又能满足该孩子，这样大饼干就能拿来给满足度比较大的孩子。因为最小的孩子最容易得到满足，所以先满足最小的孩子。

证明：假设在某次选择中，贪心策略选择给当前满足度最小的孩子分配第 m 个饼干，第 m 个饼干为可以满足该孩子的最小饼干。
     假设存在一种最优策略，给该孩子分配第 n 个饼干，并且 m < n。
     我们可以发现，经过这一轮分配，贪心策略分配后剩下的饼干一定有一个比最优策略来得大。
     因此在后续的分配中，贪心策略一定能满足更多的孩子。
     也就是说不存在比贪心策略更优的策略，即贪心策略就是最优策略。

 Note:
You may assume the greed factor is always positive.
You cannot assign more than one cookie to one child.

Example 1:
Input: [1,2,3], [1,1]

Output: 1

Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3.
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:
Input: [1,2], [1,2,3]

Output: 2

Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2.
You have 3 cookies and their sizes are big enough to gratify all of the children,
You need to output 2.
 *
 * */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 先尽量用小的去满足贪婪度小的，再用大的去满足贪婪度大的
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gi = 0;
        int sj = 0;
        while (sj < s.size()) {
            if (g[gi] <= s[sj]) {
                gi++;
            }
            sj++;
        }
        return gi;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> g = {1, 2, 3};
    vector<int> s = {2, 2};
    cout << solution->findContentChildren(g, s);
}
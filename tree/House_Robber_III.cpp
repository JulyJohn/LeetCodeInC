//
// Created by yzjhh on 2019/2/28.
//

/**
 * 337. House Robber III
 *
 * The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root."
 * Besides the root, each house has one and only one parent house.
 * After a tour, the smart thief realized that "all houses in this place forms a binary tree".
 * It will automatically contact the police if two directly-linked houses were broken into on the same night.
 * Determine the maximum amount of money the thief can rob tonight without alerting the police.
 *
 * 题目描述：求一棵树中所有非相邻节点的和的最大值。
 *

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \
     3   1

Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 *
 * */

#include "../util/BinTree.h"
#include <unordered_map>

using namespace leetcode;

class Solution {
public:

    int rob(TreeNode *root) {
//        unordered_map<TreeNode *, int> map;
//        return rob_hashmap(root, map);

        int *val = rob_greedy(root);
        int res = max(val[0], val[1]);
        delete val;
        return res;
    }

    // 方法2 贪心算法，用两个值，一个表示当前没有被偷的情况下的最大值，另一个表示当前结点被偷的情况下的最大值
    int *rob_greedy(TreeNode *root) {
        // 递归退出条件
        if (root == NULL) {
//            int *ret = {0,9};
            return new int[2]();
        }
        int *val = new int[2];
        int *val_left = rob_greedy(root->left);
        int *val_right = rob_greedy(root->right);

        // 当前结点没被偷，那么它的子结点可以是被偷也可以是不被偷的情况
        val[0] = max(val_left[0], val_left[1]) + max(val_right[0], val_right[1]);
        // 当前结点被偷，那么它的子节点只能是不被偷的情况
        val[1] = root->val + val_left[0] + val_right[0];
        return val;
    }

    // 方法1 用一个hashmap来标注某个结点是否被偷过
    int rob_hashmap(TreeNode *root, unordered_map<TreeNode *, int> map) {
        // 递归退出的条件
        if (root == NULL) {
            return 0;
        }

        // map的作用就是标记当前结点是否已经访问过和并存储当前结点可以偷到的最大值
        if (map.count(root)) {
            return map[root];
        }

        // 两种情况：
        //      1. 当前结点没有被偷，那么可以偷它的左结点和右结点
        //      2. 当前结点被偷了，那么只能是它的左结点和右结点的子节点可以被偷

        // 情况1
        int val_not_robbed = rob_hashmap(root->left, map) + rob_hashmap(root->right, map);

        // 情况2
        int val_robbed = root->val;
        if (root->left != NULL) {
            val_robbed += rob_hashmap(root->left->left, map) + rob_hashmap(root->left->right, map);
        }
        if (root->right != NULL) {
            val_robbed += rob_hashmap(root->right->left, map) + rob_hashmap(root->right->right, map);
        }

        int val = max(val_not_robbed, val_robbed);
        map.emplace(make_pair(root, val));

        // 最后返回两种情况的较大值
        return val;
    }
};

int main() {
    vector<int> arr = {3, 4, 5, 1, 3, NULL, 1};
    standard_leetcode_array(arr);
    TreeNode *root;
    creatTree(root, arr, arr.size(), 0);
    Solution *solution = new Solution();
    cout << solution->rob(root);
    return 0;
}
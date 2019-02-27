//
// Created by yzjhh on 2019/2/27.
//

/**
 *
 * 437. Path Sum III
 *
 * You are given a binary tree in which each node contains an integer value.
 *
 * 题目描述：节点和等于特定数的路径数量
 * note: 路径不一定以 root 开头，也不一定以 leaf 结尾，但是必须连续。

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
 *
 * */

#include "../util/BinTree.h"

using namespace leetcode;

class Solution {
public:
    int pathSum(TreeNode *root, int sum) {
        if (root == NULL) {
            return 0;
        }
        return pathSumStartWithRoot(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int pathSumStartWithRoot(TreeNode *root, int sum) {
        if (root == NULL) {
            return 0;
        }
        int cnt = 0;
        if (sum == root->val) {
            cnt++;
        }
        cnt += pathSumStartWithRoot(root->left, sum - root->val) + pathSumStartWithRoot(root->right, sum - root->val);
        return cnt;
    }
};
//
// Created by yzjhh on 2019/2/28.
//

/**
 * 404. Sum of Left Leaves
 *
 * Find the sum of all left leaves in a given binary tree.
 *
 * 题目描述；求二叉树所有左叶子的和。
 *

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
 * */
#include "../util/BinTree.h"

using namespace leetcode;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode *root) {
        int sum = 0;
        sumOfLeftLeavesSub(root, sum, 0);
    }

    void sumOfLeftLeavesSub(TreeNode *root, int &sum, bool isLeft) {
        if (root == NULL) {
            return;
        }
        if (isLeft && root->left == NULL && root->right == NULL) {
            sum += root->val;
        }
        sumOfLeftLeavesSub(root->left, sum, isLeft);
        sumOfLeftLeavesSub(root->right, sum, !isLeft);
    }
};
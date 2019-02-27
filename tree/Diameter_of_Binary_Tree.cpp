//
// Created by yzjhh on 2019/2/27.
//

/**
 *
 * 543. Diameter of Binary Tree
 *
 * Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
 *
 * 题目描述：求树的直径，即左右子树最大高度之和减1

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
 * */
#include "../util/BinTree.h"

using namespace leetcode;

class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        int res = 0;
        depth(root, res);
        return res;
    }

    int depth(TreeNode *root, int &maxD) {
        if (root == NULL) {
            return 0;
        }
        int nLeft = depth(root->left, maxD);
        int nRight = depth(root->right, maxD);
        maxD = max(maxD, nLeft + nRight);
        return max(nLeft, nRight) + 1;
    }
};
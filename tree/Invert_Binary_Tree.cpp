//
// Created by yzjhh on 2019/2/27.
//

/**
 * 226. Invert Binary Tree
 *
 * Invert a binary tree.
 *
 * 题目描述：反转二叉树
 *

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
 *
 * */

#include "../util/BinTree.h"

using namespace leetcode;

class Solution {
public:

    TreeNode *invertTree(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode *tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(root->left);
        return root;
    }

    // 非递归
    TreeNode *invertTree1(TreeNode *root) {
        if (root == NULL) {
            return root;
        }
        queue<TreeNode *> q;
        TreeNode *p;
        q.push(root);
        TreeNode *tmp;
        while (!q.empty()) {
            p = q.front();
            q.pop();
            if (p->left != NULL || p->right != NULL) {
                tmp = p->right;
                p->right = p->left;
                p->left = tmp;
            }
            if (p->left != NULL) {
                q.push(p->left);
            }
            if (p->right != NULL) {
                q.push(p->right);
            }
        }
    }
};
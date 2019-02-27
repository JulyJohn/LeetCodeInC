//
// Created by yzjhh on 2019/2/27.
//

/**
 *
 * 110. Balanced Binary Tree
 *
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as:
 * a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 *
 * 题目描述；判断一个二叉树是否为平衡树。
 * note: AVL树中任何节点的两个子树的高度最大差别为1。
 *

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
 *
 * */

#include "../util/BinTree.h"

using namespace leetcode;

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        bool flag = true;
        maxDepth(root, flag);
        return flag;
    }

    int maxDepth(TreeNode *root, bool &flag) {
        if (root == NULL) {
            return 0;
        }
        int nLeft = maxDepth(root->left, flag);
        int nRight = maxDepth(root->right, flag);
        if (abs(nLeft - nRight) > 1) {
            flag = false;
        }
        return max(nLeft, nRight) + 1;
    }
};

int main() {

}
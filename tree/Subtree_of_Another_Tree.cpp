//
// Created by yzjhh on 2019/2/28.
//

/**
 *
 * 572. Subtree of Another Tree
 *
 * Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
 *
 * 题目描述：判断一棵树是否为另一棵树的子树

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
 *
 * */

#include "../util/BinTree.h"

using namespace leetcode;

class Solution {
public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (s == NULL) {
            return false;
        }
        return isSubtreeWithRoot(s, t) || isSubtree(s->right, t->right) || isSubtree(s->left, t->left);
    }

    bool isSubtreeWithRoot(TreeNode *s, TreeNode *t) {
        if (t == NULL && s == NULL) {
            return true;
        }
        if (t == NULL || s == NULL) {
            return false;
        }
        if (t->val != s->val) {
            return false;
        }
        return isSubtreeWithRoot(s->left, t->left) && isSubtreeWithRoot(s->right, t->right);
    }
};
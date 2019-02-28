//
// Created by yzjhh on 2019/2/28.
//

/**
 * 687. Longest Univalue Path
 *
 * Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
 *
 * 题目描述：找出节点值完全相同的最长路径。
 *

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
 *
 * */

#include "../util/BinTree.h"

using namespace leetcode;

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        dsf(root, res);
        return res;
    }

    int dsf(TreeNode* root, int &path){
        if(root == NULL){
            return 0;
        }
        int left = dsf(root->left, path);
        int right = dsf(root->right, path);
        int lPath = root->left != NULL && root->left->val == root->val ? left + 1 : 0;
        int rPath = root->right != NULL && root->right->val == root->val ? right + 1 : 0;
        path = max(path, lPath + rPath);
        return max(lPath, rPath);
    }
};
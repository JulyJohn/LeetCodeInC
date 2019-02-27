//
// Created by yzjhh on 2019/2/26.
//

/**
 * 104. Maximum Depth of Binary Tree
 *
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 *
 * 题目描述：树的高度

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
 * */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "../util/BinTree.h"

using namespace leetcode;

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return max(maxDepth(root->right), maxDepth(root->left)) + 1;
    }
};


int main() {
    vector<int> arr = {3, 9, 20, NULL, NULL, 15, 7};
    standard_leetcode_array(arr);
    TreeNode *root;
    creatTree(root, arr, arr.size(), 0);
    preOrderRecursively(root);
    inOrderRecursively(root);
}

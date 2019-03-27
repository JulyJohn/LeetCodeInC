//
// Created by yzjhh on 2019/3/27.
//

/**
 *
 * 113. Path Sum II
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 *
 * 题目描述：返回二叉树根节点到叶子节点的路径和为某一个值的所有路径

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
 *
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
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        helper_pathSum(root, sum, res, path);
        return res;
    }

    void helper_pathSum(TreeNode* root, int sum, vector<vector<int>> &res, vector<int> &path) {
        if(root == NULL){
            return ;
        }
        path.emplace_back(root->val);
        if(root->val == sum && root->left == NULL && root->right == NULL){
            res.emplace_back(path);
            path.pop_back();
            return;
        }
        helper_pathSum(root->left, sum - root->val, res, path);
        helper_pathSum(root->right, sum - root->val, res, path);
        path.pop_back();
    }
};
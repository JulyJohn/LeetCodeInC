//
// Created by yzjhh on 2019/3/25.
//

/**
 *
 * 236. Lowest Common Ancestor of a Binary Tree
 *
 * 题目描述：二叉树的第一个公共祖先
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){
            return root;
        }
        TreeNode* node_l = lowestCommonAncestor(root->left, p, q);
        TreeNode* node_r = lowestCommonAncestor(root->right, p, q);
        if(node_l && node_r){
            return root;
        }
        return node_l ? node_l :node_r;
    }
};
//
// Created by julyjohn on 2019-03-31.
//

/**
 *
 * 98. Validate Binary Search Tree
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * 题目描述：判断一个二叉树是否为二叉搜索树

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
    2
   / \
  1   3
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
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
    // 递归
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = NULL;
        return inOrder(root, pre);
    }

    bool inOrder(TreeNode*& root, TreeNode*& pre){
        if(!root){
            return true;
        }
        // 1. 中序遍历，
        // 2. pre!=NULL的作用有两个，一个是非空判断，另一个则是当树遍历到最左边叶子节点的时候给它赋初始值（也就是整棵树的最小值）
        // 3. 要满足当前节点大于上一个节点
        if(!inOrder(root->left, pre)){
            return false;
        }
        if(pre != NULL && root->val <= pre->val){
            return false;
        }
        pre = root;
        return inOrder(root->right, pre);
    }

    // 非递归
    // bool isValidBST(TreeNode* root) {
    //     stack<TreeNode* > s;
    //     TreeNode* pre_node = NULL;
    //     TreeNode* p = root;
    //     while(!s.empty() || p){
    //         while(p){
    //             s.push(p);
    //             p = p->left;
    //         }
    //         if(!s.empty()){
    //             p = s.top();
    //             if(!pre_node || (pre_node && p->val > pre_node->val)){
    //                 pre_node = p;
    //             }else{
    //                 return false;
    //             }
    //             s.pop();
    //             p = p->right;
    //         }
    //     }
    //     return true;
    // }
};
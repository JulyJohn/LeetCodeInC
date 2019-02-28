//
// Created by yzjhh on 2019/2/28.
//

/**
 *
 * 111. Minimum Depth of Binary Tree
 *
 * Given a binary tree, find its minimum depth.
 *
 * 题目描述： 求树的最小深度

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
 *
 * */

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL){
            return minDepth(root->right)+1;
        }
        if(root->right == NULL){
            return minDepth(root->left)+1;
        }
        return min(minDepth(root->right), minDepth(root->left))+1;

        // 非递归
        // queue<TreeNode* > q;
        // q.push(root);
        // int depth = 0;
        // while(!q.empty()){
        //     depth++;
        //     for(int i = 0, n = q.size(); i < n; i++){
        //         TreeNode* p = q.front();
        //         if(p->left != NULL){
        //             q.push(p->left);
        //         }
        //         if(p->right != NULL){
        //             q.push(p->right);
        //         }
        //         if(p->left == NULL && p->right == NULL){
        //             return depth;
        //         }
        //         q.pop();
        //     }
        // }
        // return depth;
    }
};
//
// Created by yzjhh on 2019/3/4.
//

/**
 *
 * 671. Second Minimum Node In a Binary Tree
 *
 * Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node.
 * If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.
 * Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
 * If no such second minimum value exists, output -1 instead.
 *
 * 题目描述：给定一棵二叉树满足：每个结点都包含偶数个结点（0或2），并且是它的叶子节点中的较小值，找出二叉树中第二小的节点。
 *

Example 1:
Input:
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:
Input:
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
 *
 * */


class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(!root){
            return -1;
        }
        int second = INT32_MAX, first = root->val;
        bool has_changed = false;
        preOrder(root, second, first, has_changed);
        return has_changed ? second : -1;
    }

    void preOrder(TreeNode* root, int &second, int first, bool &has_changed){
        if(!root){
            return ;
        }
        if(root->val != first && root->val <= second){
            second = root->val;
            has_changed = true;
        }
        preOrder(root->left, second, first, has_changed);
        preOrder(root->right, second, first, has_changed);
    }
};

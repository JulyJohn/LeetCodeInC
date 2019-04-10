//
// Created by yzjhh on 2019/4/10.
//
/**
 *
 * 二叉搜索树与双向链表
 *
 * note：中序遍历即可，同时用一个指针记录上一个节点，然后将两个节点连起来
 *
 * */
 
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    TreeNode *Convert(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode *res = NULL;
        inOrder(root, res);
        while (root->left) {
            root = root->left;
        }
        return root;
    }

    void inOrder(TreeNode *cur, TreeNode *&pre) {
        if (cur == NULL) {
            return;
        }
        inOrder(cur->left, pre);
        cur->left = pre;
        if (pre) {
            pre->right = cur;
        }
        pre = cur;
        inOrder(cur->right, pre);
    }
};
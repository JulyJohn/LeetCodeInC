//
// Created by julyjohn on 2019-04-01.
//

/**
 *
 * 二叉搜索树的第k个节点
 *
 * note：二叉搜索树中序遍历有序
 *
 * */

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(k == 0){
            return NULL;
        }
        return inOrder(pRoot, k);
    }

    TreeNode* inOrder(TreeNode* pRoot, int k){
        stack<TreeNode* > s;
        TreeNode* cur = pRoot;
        while(cur || !s.empty()){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }
            if(!s.empty()){
                cur = s.top();
                s.pop();
                if(--k < 0){
                    return cur;
                }
                cur = cur->right;
            }
        }
        return NULL;
    }
};
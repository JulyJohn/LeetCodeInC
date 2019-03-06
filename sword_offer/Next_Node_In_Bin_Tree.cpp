//
// Created by yzjhh on 2019/3/6.
//

/**
 *
 * 8. 二叉树的下一个结点
 *
 * 题目描述：给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
 *
 * */
#include <iostream>

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        // 三种情况
        // 1. 右结点不为空，那么右结点的左叶子结点就是下一个结点
        // 2. 右结点为空，那么沿着树往上找，第一个左结点的父节点便是要找的结点
        if(pNode == NULL){
            return NULL;
        }
        TreeLinkNode* r_node = pNode->right;
        TreeLinkNode* parent_node;
        if(r_node != NULL){
            while(r_node->left != NULL){
                r_node = r_node->left;
            }
            return r_node;
        }else{
            while(pNode->next != NULL){
                parent_node = pNode->next;
                if(parent_node->left == pNode){
                    return parent_node;
                }
                pNode = pNode->next;
            }
        }
        return NULL;
    }
};

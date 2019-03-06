//
// Created by yzjhh on 2019/3/6.
//

/**
 * 7. 重建二叉树
 *
 * 题目描述：根据二叉树的前序遍历和中序遍历的结果，重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

    preorder = [3,9,20,15,7]
    inorder =  [9,3,15,20,7]
 *
 * */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.size() == 0) {
            return NULL;
        }
        stack<TreeNode *> pre_stack;
        int pre_idx = 0;
        int in_idx = 0;
        TreeNode *root = new TreeNode(pre[pre_idx++]);
        pre_stack.push(root);
        TreeNode *cur_node = pre_stack.top();
        bool is_right = false;
        // 默认往左子树方向处理，
        // 两种情况：
        // 1. 如果栈顶元素与中序数组当前值相等时，说明左节点处理完了，出栈，接下来要处理右节点；
        // 2. 如果不相等，说明还有左节点，压栈，继续往下走
        while (pre_idx < pre.size()) {
            if (!pre_stack.empty() && pre_stack.top()->val == vin[in_idx]) {
                cur_node = pre_stack.top();
                pre_stack.pop();
                ++in_idx;
                is_right = true;
            } else if (!is_right) {
                TreeNode *l_node = new TreeNode(pre[pre_idx++]);
                cur_node->left = l_node;
                cur_node = l_node;
                pre_stack.push(cur_node);
            } else {
                TreeNode *r_node = new TreeNode(pre[pre_idx++]);
                cur_node->right = r_node;
                cur_node = r_node;
                pre_stack.push(cur_node);
                is_right = false;
            }
        }
        return root;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> a = {3, 9, 20, 15, 7};
    vector<int> b = {9, 3, 15, 20, 7};
    solution->reConstructBinaryTree(a, b);
    return 0;
}
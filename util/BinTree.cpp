//
// Created by yzjhh on 2018/10/27.
//

#include "BinTree.h"

namespace leetcode {

    /**
     * 求二叉树深度（非递归）
     *
     * 方法：层次遍历，记录层数
     * */
    int getTreeDepthIteratively(TreeNode *root) {
        queue<TreeNode *> q;
        TreeNode *p;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            depth++;
            int curQSize = q.size();
            int cnt = 0;
            while (cnt++ < curQSize) {
                p = q.front();
                q.pop();
                if (p->left != NULL) {
                    q.push(p->left);
                }
                if (p->right != NULL) {
                    q.push(p->right);
                }
            }
        }
        return depth;
    }

    /**
     * 求二叉树深度（递归）
     *
     * 方法：等于左右子树深度的最大值+1
     * */
    int getTreeDepthRecursively(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return max(getTreeDepthRecursively(root->left), getTreeDepthRecursively(root->right)) + 1;
    }

    /**
     * 先序遍历(非递归)
     * */
    void preOrderIteratively(TreeNode *root) {
        stack<TreeNode *> s;
        TreeNode *p = root;
        while (!s.empty() || p != NULL) {
            // 压栈,一直到最后一个左子节点
            while (p != NULL) {
                cout << p->val << ", ";
                s.push(p);
                p = p->left;
            }
            // 左子树到头了，现在开始访问右子树
            if (!s.empty()) {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
    }

    /**
     * 中序遍历(非递归)
     * */
    void inOrderIteratively(TreeNode *root) {
        stack<TreeNode *> s;
        TreeNode *p = root;
        while (!s.empty() || p != NULL) {
            // 压栈,一直到最后一个左子节点
            while (p != NULL) {
                s.push(p);
                p = p->left;
            }
            // 左子树到头了，现在开始访问右子树
            if (!s.empty()) {
                p = s.top();
                cout << p->val << ", ";
                s.pop();
                p = p->right;
            }
        }
    }

    /**
     * 后序遍历(非递归)
     * */
    void postOrderIteratively(TreeNode *root) {
        stack<TreeNode *> s;
        TreeNode *pre = NULL;
        TreeNode *cur = NULL;
        s.push(root);
        while (!s.empty()) {
            cur = s.top();
            // 当前结点的左右子结点都为空，说明已经到底了，不管它是左结点还是右结点，都可以访问了；
            // 或者它的左右孩子都被访问过了，此时也可以对其访问。
            if ((cur->left == NULL && cur->right == NULL) || (pre != NULL && (pre == cur->left || pre == cur->right))) {
                cout << cur->val << ", ";
                s.pop();
                pre = cur;
            } else { // 保证右结点先入栈，左结点后入栈
                if (cur->right != NULL) {
                    s.push(cur->right);
                }
                if (cur->left != NULL) {
                    s.push(cur->left);
                }
            }
        }
    }

    /**
     * 层次遍历
     *
     * 采用队列来实现
     * */
    void layerOrder(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        queue<TreeNode *> q;
        TreeNode *p = NULL;
        q.push(root);
        while (!q.empty()) {
            p = q.front();
            cout << p->val << ", ";
            q.pop();
            if (p->left != NULL) {
                q.push(p->left);
            }
            if (p->right != NULL) {
                q.push(p->right);
            }
        }
    }

    /**
     * 先序遍历(递归)
     * */
    void preOrderRecursively(TreeNode *root) {
        if (root != NULL) {
            cout << root->val << ", "; // 先序遍历
            preOrderRecursively(root->left);
            preOrderRecursively(root->right);
        }
    }

    /**
     * 中序遍历(递归)
     * */
    void inOrderRecursively(TreeNode *root) {
        if (root != NULL) {
            inOrderRecursively(root->left);
            cout << root->val << ", "; // 中序遍历
            inOrderRecursively(root->right);
        }
    }

    /**
     * 后序遍历(递归)
     * */
    void postOrderRecursively(TreeNode *root) {
        if (root != NULL) {
            postOrderRecursively(root->left);
            postOrderRecursively(root->right);
            cout << root->val << ", "; // 后序遍历
        }
    }

    /**
     * 遍历二叉树
     * */
    void printTree(TreeNode *root) {

        if (root == NULL) {
            return;
        }

        printTree(root->left);
        cout << root->val << ", "; // 中序遍历
        printTree(root->right);
    }

    /**
     * 标准化leetcode数组
     *
     * 将leetcode输入的树结点数组转换成标准的树结点数组（len = 2^n -1 ）
     * */
    void standard_leetcode_array(vector<Dtype> &arr) {
        int i = 0;
        while (i < arr.size()) {
            if (arr[i] == 0 && (i * 2 + 2) < arr.size()) {
                arr.insert(arr.begin() + i * 2 + 1, (Dtype) NULL);
                arr.insert(arr.begin() + i * 2 + 2, (Dtype) NULL);
            }
            i++;
        }
    }

    /**
     * 构建二叉树
     * */
    void creatTree(TreeNode *&root, vector<Dtype> arr, int len, int idx) {
        if (idx > len - 1) {
            return;
        }
        if (arr[idx] == NULL) {
            root = NULL;
        } else {
            root = new TreeNode(arr[idx]);
        }
        if (arr[idx] != NULL) {
            creatTree(root->left, arr, len, 2 * idx + 1);
            creatTree(root->right, arr, len, 2 * idx + 2);
        }
    }
}
//
// Created by yzjhh on 2018/10/25.
//

/**
 *
 * 897. Increasing Order Search Tree
 * Given a tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree,
 * and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9

 * Note:
 * The number of nodes in the given tree will be between 1 and 100.
 * Each node will have a unique integer value from 0 to 1000.

 * */

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

typedef int Dtype;

//Definition for a binary tree node.
struct TreeNode {
    Dtype val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 遍历二叉树
 * */
void printTree(TreeNode *root) {

    if (root == NULL) {
        cout << "null, "; // 先序遍历
        return;
    }

    if(root->left == NULL && root->right == NULL){
        cout << root->val << ", "; // 先序遍历
        return;
    }
//    cout << root->val << ", "; // 先序遍历
    printTree(root->left);
    cout << root->val << ", "; // 中序遍历
    printTree(root->right);
//    cout << root->val << ", "; // 后序遍历
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

class Solution {
public:

    TreeNode *cur_;

    void printTree(TreeNode *root) {
        if (root == NULL) {
            cout << "null, "; // 先序遍历
            return;
        }

        if(root->left == NULL && root->right == NULL){
            cout << root->val << ", "; // 先序遍历
            return;
        }

        cout << root->val << ", "; // 先序遍历
        printTree(root->left);
        printTree(root->right);
    }

    void increasingBST_(TreeNode *root) {
        if (root == NULL) {
            return;
        }

        increasingBST_(root->left);
//        cout << root->val << ", "; // 中序遍历
        root->left = NULL;
        cur_->right = root;
        cur_ = root;

        increasingBST_(root->right);
    }

    TreeNode *increasingBST(TreeNode *root) {
        TreeNode *ans = new TreeNode(0);
        cur_ = ans;
        increasingBST_(root);
        printTree(ans->right);
    }

    void increasingBST1_(TreeNode *root, vector<Dtype> &node_vec) {
        if (root == NULL) {
            return;
        }

        increasingBST1_(root->left, node_vec);
//        cout << root->val << ", "; // 中序遍历
        node_vec.push_back(root->val);
        increasingBST1_(root->right, node_vec);
    }


    TreeNode *increasingBST1(TreeNode *root) { // 该解法更符合实际的生产环境
        vector<Dtype > node_vec;
        increasingBST1_(root, node_vec);
        TreeNode *ans = new TreeNode(0);
        TreeNode *cur = ans;
        for(Dtype node : node_vec){
            cur->left = NULL;
            cur->right = new TreeNode(node);
            cur = cur->right;
        }
        printTree(ans->right);
    }
};

int main() {
    Solution *s = new Solution();

    vector<Dtype> arr = {5, 3, 6, 2, 4, NULL, 8, 1, NULL, NULL, NULL, 7, 9};
    standard_leetcode_array(arr);
    TreeNode *root;
    int start_idx = 0;
    creatTree(root, arr, arr.size(), start_idx);
    printTree(root);
    cout << endl;

    auto func_beg = system_clock::now();
    long loop_num = 1;
    for (int i = 0; i < loop_num; ++i) {
        s->increasingBST1(root);
    }
    auto func_duration = duration_cast<milliseconds>(system_clock::now() - func_beg);
    cout << endl << "func_duaration: " << func_duration.count() << endl;
}
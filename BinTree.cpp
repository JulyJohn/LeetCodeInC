//
// Created by yzjhh on 2018/10/27.
//

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


int main() {

    vector<Dtype> arr = {5, 3, 6, 2, 4, NULL, 8, 1, NULL, NULL, NULL, 7, 9};
//    vector<int> arr = {1, NULL, 3, NULL, 7};
    standard_leetcode_array(arr);
    TreeNode *root;
    creatTree(root, arr, arr.size(), 0);
    printTree(root);

}
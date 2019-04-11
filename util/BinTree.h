//
// Created by yzjhh on 2019/2/26.
//

#ifndef LEETCODEINCPLUS_BINTREE_H
#define LEETCODEINCPLUS_BINTREE_H

#include <iostream>
#include <vector>
#include <chrono>
#include <stack>
#include <queue>

namespace leetcode {

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

    int getTreeDepthIteratively(TreeNode *root);

    int getTreeDepthRecursively(TreeNode *root);

    void preOrderIteratively(TreeNode *root);

    void inOrderIteratively(TreeNode *root);

    void postOrderIteratively(TreeNode *root);

    void preOrderRecursively(TreeNode *root);

    void inOrderRecursively(TreeNode *root);

    void postOrderRecursively(TreeNode *root);

    void layerOrder(TreeNode *root);

    void printTree(TreeNode *root);

    void standard_leetcode_array(vector<Dtype> &arr);

    void creatTree(TreeNode *&root, vector<Dtype> arr, int len, int idx);

    TreeNode* stringToTreeNode(string input);
}


#endif //LEETCODEINCPLUS_BINTREE_H

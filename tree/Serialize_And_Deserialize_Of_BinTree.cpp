//
// Created by yzjhh on 2019/4/11.
//

/**
 * 二叉树的序列化和反序列化
 *
 * note：层次遍历+stringstream
 * */

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}


TreeNode *stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        ostringstream out;
        if(!root){
            return out.str();
        }
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            TreeNode* p = q.front();
            q.pop();
            if(p){
                out << p->val << " "; // stream默认以空格作为分隔符
                q.push(p->left);
                q.push(p->right);
            }else{
                out << "# ";
            }
        }
        return out.str();
    }

    TreeNode *deserialize(string data) {
        istringstream in(data);
        string node_str;
        if(!(in >> node_str)){
            return NULL;
        }
        TreeNode* root = new TreeNode(atoi(node_str.c_str()));
        TreeNode* node = root;
        queue<TreeNode* > q;
        q.push(node);
        while(!q.empty()){
            TreeNode* p = q.front();
            q.pop();
            // 左结点
            if(!(in >> node_str)){
                break;
            }
            if(node_str != "#"){
                node = new TreeNode(atoi(node_str.c_str()));
                p->left = node;
                q.push(node);
            }
            // 右结点
            if(!(in >> node_str)){
                break;
            }
            if(node_str != "#"){
                node = new TreeNode(atoi(node_str.c_str()));
                p->right = node;
                q.push(node);
            }
        }
        return root;
    }

//    // [1,2,3,null,null,4,5] => [1,2,#,#,3,4,#,#,5,#,#]
//    string serialize(TreeNode *root) {
//        if (!root) {
//            return "#";
//        }
//        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
//    }
//
//    // Decodes your encoded data to tree.
//    TreeNode *deserialize(string data) {
//        return helper(data);
//    }
//    TreeNode* helper(string &data){
//        if (data.empty()) {
//            return NULL;
//        }
//        int split_idx = data.find_first_of(",");
//        string node_str = split_idx == -1 ? data : data.substr(0, split_idx);
//        data = split_idx == -1 ? "" : data.substr(split_idx + 1);
//        if (node_str == "#") {
//            return NULL;
//        }
//        TreeNode *root = new TreeNode(atoi(node_str.c_str()));
//        root->left = helper(data);
//        root->right = helper(data);
//        return root;
//    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    Codec *codec = new Codec();
    string input = "[1,2,3,null,null,4,5]";
    TreeNode *root = stringToTreeNode(input);
    TreeNode *new_root = codec->deserialize(codec->serialize(root));
    return 0;
}
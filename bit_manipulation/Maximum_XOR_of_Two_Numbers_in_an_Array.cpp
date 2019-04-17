//
// Created by yzjhh on 2019/4/17.
//

/**
 *
 * 421. Maximum XOR of Two Numbers in an Array
 *
 * 题目描述：求数组中任意两个数的与值的最大值，要求时间复杂度为O(n)
 *
 * note：字典树、bit_manipulation
 *
 * */
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct TrieNode {
    bool val;
    TrieNode *left;
    TrieNode *right;

    TrieNode(bool v) : val(v), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        TrieNode *root = new TrieNode(0);
        TrieNode *cur_node;
        // build the trie, 左子树表示1，右子树表示0
        // 从根结点到每一个子节点都表示一个数
        for (int num : nums) {
            cur_node = root;
            for (int i = 30; i >= 0; --i) {
                if ((num >> i) & 1) {
                    if (cur_node->left == NULL) {
                        cur_node->left = new TrieNode(true);
                    }
                    cur_node = cur_node->left;
                } else {
                    if (cur_node->right == NULL) {
                        cur_node->right = new TrieNode(false);
                    }
                    cur_node = cur_node->right;
                }
//                cout << cur_node->val;
            }
//            cout << endl;
        }

        int max_val = 0;
        // 遍历每个num
        for (int num : nums) {
            int res = 0;
            cur_node = root;
            for (int i = 30; i >= 0; --i) {
                int tmp = num & (1 << i);
                if (cur_node->left && cur_node->right) { // 如果当前结点既有左结点又有右结点，那么选择使得异或值为1的那一边
                    if (tmp == 1) {
                        cur_node = cur_node->right;
                    } else {
                        cur_node = cur_node->left;
                    }
                } else { // 否则，只能选择非空的一边
                    cur_node = cur_node->left ? cur_node->left : cur_node->right;
                }
                res |= tmp ^ ((int) cur_node->val << i);
            }
            max_val = max(res, max_val);
        }
        return max_val;
    }

    int findMaximumXOR(vector<int> &nums) {
        int mask = 0; // mask = 1111..1000..00，表示最高位到第i位为1，其余位为0
        int test_max = 0;
        int max = 0;
        unordered_set<int> s; // set记录的是元素中第i位为1的所有情况，例如mask = 11...1000， nums = [12, 10, 7] = [1100, 1010, 0111]，那么s = [1000, 1000, 0000]，因为只有12和10的第4位是为1
        for (int i = 30; i >= 0; --i) {
            mask |= 1 << i;
            for (int num : nums) {
                s.insert(num & mask);
            }
            // 如果max的第i位为1，那么这个1肯定由某两个元素的第i位的异或生成
            // 即test_max == a ^ b，其中a和b都是s中的元素，
            // 再由异或的性质，c = a ^ b，则c ^ b = a ^ b ^ b = a ^ (b ^ b) = a，即a = c ^ b
            // test_max == a ^ b可以转换为判断test_max ^ a是否在s中
            test_max = max | 1 << i;
            for (int s_val : s) {
                if (s.find(s_val ^ test_max) != s.end()) {
                    max = test_max; // test_max满足要求，则更新max
                    break;
                }
            }
            s.clear();
        }
        return max;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << solution->findMaximumXOR(nums);
    return 0;
}
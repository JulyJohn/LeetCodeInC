//
// Created by yzjhh on 2019/2/26.
//

/**
 *
 * 725. Split Linked List in Parts
 *
 * Given a (singly) linked list with head node root, write a function to split the linked list into k consecutive linked list "parts".
 * The length of each part should be as equal as possible: no two parts should have a size differing by more than 1.
 * This may lead to some parts being null.
 * The parts should be in order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal parts occurring later.
 * Return a List of ListNode's representing the linked list parts that are formed.
 *
 * 题目描述：把链表分隔成 k 部分，每部分的长度都应该尽可能相同，排在前面的长度应该大于等于后面的。
 *

Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
Example 1:
Input:
root = [1, 2, 3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The input and each element of the output are ListNodes, not arrays.
For example, the input root has root.val = 1, root.next.val = 2, \root.next.next.val = 3, and root.next.next.next = null.
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but it's string representation as a ListNode is [].
Example 2:
Input:
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
Note:

The length of root will be in the range [0, 1000].
Each value of a node in the input will be an integer in the range [0, 999].
k will be an integer in the range [1, 50].
 * */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode *> splitListToParts(ListNode *root, int k) {
        vector<ListNode *> res(k);

        if (root == NULL) {
            return res;
        }


        int n = 0;
        // 先得出链表的长度
        ListNode *cur = root;
        while (cur != NULL) {
            n++;
            cur = cur->next;
        }

        int part_size = n / k;
        int mod = n % k;

        cur = root;
        ListNode *prev = cur;
        for (int i = 0; cur != NULL && i < k; ++i) {
            res[i] = cur;
            int cur_part_size = (mod-- > 0) ? part_size + 1 : part_size;
            for (int j = 0; j < cur_part_size; ++j) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = NULL;
        }

        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
//    l1->next->next->next = new ListNode(4);
//    l1->next->next->next->next = new ListNode(5);
    int k = 5;
    vector<ListNode *> res = solution->splitListToParts(l1, k);
    std::cout << "";
}

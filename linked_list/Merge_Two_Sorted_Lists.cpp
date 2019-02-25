//
// Created by yzjhh on 2019/2/25.
//

/**
 * 21. Merge Two Sorted Lists
 *
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 *
 * 题目描述：将两个排序好的链表合并成一个新的链表，

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
 * */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     *
     * 注意，当其中一个链表遍历完了以后，另一个链表可能还没有遍历完，此时直接将另一个链表插入到队尾即可。
     *
     * 扩展：尾插法，得到一个递增的序列；而如果使用头插法，则可以得到一个递减的序列。
     * */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode(-1);
        ListNode *l = res;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                l->next = l1;
                l1 = l1->next;
            } else {
                l->next = l2;
                l2 = l2->next;
            }
            l = l->next;
        }
        if (l1 != NULL) {
            l->next = l1;
        }
        if (l2 != NULL) {
            l->next = l2;
        }
        return res->next;
    }
};

int main() {
    Solution *solution = new Solution();
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode *res = solution->mergeTwoLists(l1, l2);
    std::cout << "";
}
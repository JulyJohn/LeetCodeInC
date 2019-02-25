//
// Created by yzjhh on 2019/2/25.
//

/**
 *
 * 83. Remove Duplicates from Sorted List
 *
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * 题目描述：从链表中刪除重复元素

Example 1:

Input: 1->1->2
Output: 1->2

Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
 * */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *cur = head;
        ListNode *next = cur->next;
        while (next != NULL) {
            if (cur->val == next->val) {
                cur->next = next->next;
                next = cur->next;
            } else {
                cur = next;
                next = next->next;
            }
        }
        return head;
    }
};

int main() {
    Solution *solution = new Solution();
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(1);
    l1->next->next = new ListNode(2);
    l1->next->next->next = new ListNode(3);
    l1->next->next->next->next = new ListNode(3);
    ListNode *res = solution->deleteDuplicates(l1);
    std::cout << "";
}
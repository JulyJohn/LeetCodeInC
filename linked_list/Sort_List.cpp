//
// Created by yzjhh on 2019/2/27.
//

/**
 * 148. Sort List
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 *
 * 题目描述：链表排序，要求时间复杂度为O(nlogn)，空间复杂度为常数
 * note：链表的归并排序

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
     * Example:
        Input: 1->2->4, 1->3->4
        Output: 1->1->2->3->4->4
     * */
    ListNode *mergeList(ListNode *l1, ListNode *l2) {
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

    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head1 = slow->next;
        slow->next = NULL;
        ListNode *head2 = head;
        head1 = sortList(head1);
        head2 = sortList(head2);
        return mergeList(head1, head2);
    }
};

int main() {
    Solution *solution = new Solution();
    ListNode *l1 = new ListNode(4);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(1);
    l1->next->next->next = new ListNode(3);
    l1 = solution->sortList(l1);
    std::cout << std::endl;
}
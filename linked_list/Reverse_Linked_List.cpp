//
// Created by yzjhh on 2019/2/25.
//

/**
 *
 * 206. Reverse Linked List
 *
 * Reverse a singly linked list.
 *
 * 单链表反转

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
 *
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
     * 非递归方式
     * */
    ListNode *reverseList(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *cur = head;
        ListNode *next = cur->next;
        while (next != NULL) {
            cur->next = next->next;
            next->next = head;
            head = next;
            next = cur->next;
        }
        return head;
    }

    /**
     * 递归方式
     * */
    ListNode *reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};
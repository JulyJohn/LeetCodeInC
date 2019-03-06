//
// Created by yzjhh on 2019/3/6.
//

/**
 * 92. Reverse Linked List II
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 *
 * 题目描述：在m到n的位置反转一个链表

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
 *
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n || head == NULL || head->next == NULL){
            return head;
        }

        ListNode *new_head = new ListNode(-1);
        new_head->next = head;
        ListNode* front_tail = new_head;
        int i = 0;
        while(++i < m){
            front_tail = front_tail->next;
        }

        ListNode* start = front_tail->next;
        ListNode* tail = start;
        while(i++ < n){
            ListNode* tmp = tail->next;
            tail->next = tail->next->next;
            tmp->next = start;
            start = tmp;
        }
        front_tail->next = start;

        return new_head->next;
    }
};
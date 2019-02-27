//
// Created by yzjhh on 2019/2/27.
//

/**
 * 147. Insertion Sort List
 *
 * Sort a linked list using insertion sort.
 *
 * 题目描述：使用插入排序对链表进行排序。
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *preHead = new ListNode(INT32_MIN);
        ListNode *tmp;
        while (head) {
            ListNode *cur = preHead;
            while (cur->next && cur->next->val < head->val) {
                cur = cur->next;
            }
            tmp = head->next;
            head->next = cur->next;
            cur->next = head;
            head = tmp;
        }
        head = preHead->next;
        delete (preHead);
        return head;
    }

    ListNode *insertionSortList1(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *res = new ListNode(-1);
        res->next = head;
        ListNode *pre = head;
        ListNode *cur = head->next;
        ListNode *next;
        while (cur != NULL) {
            next = cur->next;
            ListNode *l = res->next;
            ListNode *l_pre = res;
            while (l != cur) {
                if (l->val < cur->val) {
                    l_pre = l;
                    l = l->next;
                } else {
                    break;
                }
            }
            if (l == cur) {
                pre = cur;
            } else {
                pre->next = next;
                l_pre->next = cur;
                cur->next = l;
            }
            cur = next;
        }
        return res->next;
    }
};
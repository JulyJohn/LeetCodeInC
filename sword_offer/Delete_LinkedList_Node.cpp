//
// Created by yzjhh on 2019/3/8.
//

/**
 * 18.1 在 O(1) 时间内删除链表节点
 * */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deletNode(ListNode *head, ListNode *tobeDelete) {
    if (head == NULL || tobeDelete == NULL) {
        return NULL;
    }
    if (tobeDelete->next != NULL) { // 该节点不是尾节点，那么将下一个节点的值复制到当前节点，同时删除下一个节点，时间复杂度O(1)
        tobeDelete->val = tobeDelete->next->val;
        tobeDelete->next = tobeDelete->next->next;
    } else if (head == tobeDelete) { // 如果与头节点相等，说明只有一个节点，直接置为NULL
        head = NULL;
    } else { // 是尾节点，则需要遍历链表，找到要删除节点的上一节点，给该节点的下一节点置为NULL
        ListNode *cur = head;
        while (cur != NULL && cur->next != tobeDelete) {
            cur = cur->next;
        }
        cur->next = NULL;
    }
    return head;
}
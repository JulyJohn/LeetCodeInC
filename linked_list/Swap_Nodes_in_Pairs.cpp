//
// Created by yzjhh on 2019/2/25.
//

/**
 * 24. Swap Nodes in Pairs
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 *
 * 题目描述：交换链表的相邻结点
 *

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
 * */
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *cur = head;
        ListNode *next = cur->next;
        ListNode *prev = new ListNode(-1);
        head = prev;
        while (cur != NULL && next != NULL) {
            cur->next = next->next; // 摘掉后面的结点 1->3
            next->next = cur; // 将后面的结点插到头部 2->1->3
            prev->next = next; //与上一个节点对的尾相连 -1->2->1->3
            prev = cur; // 记录当前节点对的尾 prev=1
            cur = cur->next; // 跳到下一节点对的头 cur=3
            if (cur != NULL) { // 此时的cur可能为NULL
                next = cur->next;
            }
        }
        return head->next;
    }
};

int main() {
    Solution *solution = new Solution();
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
//    l1->next->next = new ListNode(3);
//    l1->next->next->next = new ListNode(4);
//    l1->next->next->next->next = new ListNode(5);
//    int n = 2;
    ListNode *res = solution->swapPairs(l1);
    std::cout << "";
}



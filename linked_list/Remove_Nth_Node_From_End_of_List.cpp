//
// Created by yzjhh on 2019/2/25.
//

/**
 * 19. Remove Nth Node From End of List
 *
 * Given a linked list, remove the n-th node from the end of list and return its head.
 *
 * 题目描述： 给出一个链表，刪除倒数第n个元素，并返回它的头

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

 * */


#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fast = head;
        for (int i = 1; i <= n; ++i) {
            fast = fast->next;
        }
        if(fast == NULL){ // 说明要删除的是第一个
            return head->next;
        }
        ListNode *slow = head;
        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

int main() {
    Solution *solution = new Solution();
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    int n = 2;
    ListNode *res = solution->removeNthFromEnd(l1, n);
    std::cout << "";
}
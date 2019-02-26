//
// Created by yzjhh on 2019/2/26.
//

/**
 *
 * 328. Odd Even Linked List
 *
 * Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
 *
 * 题目描述：链表元素按奇偶聚集

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
 * */
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *lo = head;
        ListNode *le = head->next;
        ListNode *eHead = le;
        while (le != NULL && le->next != NULL) {
            lo->next = le->next;
            lo = le->next;
            le->next = lo->next;
            le = lo->next;
        }
        lo->next = eHead;
        return head;
    }
};

int main() {
    Solution *solution = new Solution();
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
//    l1->next->next = new ListNode(3);
//    l1->next->next->next = new ListNode(4);
//    l1->next->next->next->next = new ListNode(5);
    ListNode *res = solution->oddEvenList(l1);
    std::cout << "";
}

//
// Created by yzjhh on 2019/2/26.
//

/**
 * 234. Palindrome Linked List
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * 题目描述：给出一个单链表，确定它是否是一个回文。

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
 * */


#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *reverseLinkedList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *cur = head->next;
        ListNode *res = head;
        while (cur != NULL) {
            head->next = cur->next;
            cur->next = res;
            res = cur;
            cur = head->next;
        }
        return res;
    }

    bool isPalindrome(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        // 先将链表平均分成两段
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        //将后半段反转
        fast = reverseLinkedList(fast);
        slow = head;
        while (fast != NULL) {
            if(slow->val != fast->val){
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};


int main() {
    Solution *solution = new Solution();
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(2);
    l1->next->next->next = new ListNode(1);
    std::cout << solution->isPalindrome(l1);
}
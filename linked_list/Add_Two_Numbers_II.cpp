//
// Created by yzjhh on 2019/2/25.
//

/**
 * 445. Add Two Numbers II
 *
 * You are given two non-empty linked lists representing two non-negative integers.
 * The most significant digit comes first and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * 题目描述：将两个链表按十进制相加求和，要求不能修改原始链表。

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
 *
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
    stack<int> buildStackFromList(ListNode *head) {
        ListNode *l = head;
        stack<int> res;
        while (l != NULL) {
            res.push(l->val);
            l = l->next;
        }
        return res;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        stack<int> s1 = buildStackFromList(l1);
        stack<int> s2 = buildStackFromList(l2);
        int s1_val;
        int s2_val;
        int carry = 0;
        int sum = 0;
        ListNode *res = new ListNode(-1);
        while (!s1.empty() || !s2.empty() || carry != 0) {
            s1_val = s1.empty() ? 0 : s1.top();
            s2_val = s2.empty() ? 0 : s2.top();
            sum = s1_val + s2_val + carry;
            ListNode *l_tmp = new ListNode(sum % 10);
            l_tmp->next = res->next;
            res->next = l_tmp;
            carry = sum / 10;
            if (!s1.empty()) {
                s1.pop();
            }
            if (!s2.empty()) {
                s2.pop();
            }
        }
        return res->next;
    }

    ListNode* addTwoNumbers_2(ListNode* a, ListNode* b) {
        // write code here
        ListNode* res = new ListNode(-1);
        int carry = 0;
        ListNode* cur = res;
        while(a && b){
            int val = carry + a->val + b->val;
            cur->next = new ListNode(val % 10);
            carry = val / 10;
            a = a->next;
            b = b->next;
            cur = cur->next;
        }
        cur->next = a ? a : b;
        if(cur->next){
            cur->next->val += carry;
        }else if(carry != 0){
            cur->next = new ListNode(carry);
        }
        return res->next;
    }
};


int main() {
    Solution *solution = new Solution();
    ListNode *l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode *res = solution->addTwoNumbers(l1, l2);
    std::cout << "";
}
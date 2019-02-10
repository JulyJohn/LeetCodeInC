//
// Created by yzjhh on 2019/2/10.
//

/**
 *
 * 142. Linked List Cycle II

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

 题目大意：对于一个链表，如果存在回路则返回环的起始点。

Note: Do not modify the linked list.


Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.




Follow up:
Can you solve it without using extra space?
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(1){
            if(fast == NULL || fast->next == NULL){
                return NULL;
            }
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){ // 找到相遇点
                break;
            }
        }
        slow = head;
        while(1){
            if(slow == fast){
                return slow;
            }
            slow = slow->next;
            fast = fast->next;
        }
    }
};
//
// Created by yzjhh on 2019/3/26.
//

/**
 *
 * 25. Reverse Nodes in k-Group
 *
 * 题目描述：每k个一组，反转链表
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
    int countList(ListNode* head){
        int cnt = 0;
        ListNode* cur = head;
        while(cur){
            ++cnt;
            cur = cur->next;
        }
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(countList(head) < k ){
            return head;
        }
        ListNode* cur = head;
        ListNode* prev = NULL; // prev是当前的头结点
        ListNode* next;
        for(int i = 0; i < k; ++i){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        // 1. 之前的头结点变成了现在的尾节点
        // 2. cur结点此时已经到达了之前的尾节点的后一个结点，继续往后走
        head->next = reverseKGroup(cur, k);
        return prev;
    }

};
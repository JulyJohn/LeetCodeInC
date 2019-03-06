//
// Created by yzjhh on 2019/3/6.
//

/**
 * 6. 逆序链表
 *
 * 题目：描述从尾到头反过来打印出每个结点的值。
 *
 * */
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int > res;
        if(head == NULL){
            return res;
        }
        ListNode *tail = head;
        while(tail->next != NULL){
            ListNode *tmp = tail->next;
            tail->next = tail->next->next;
            tmp->next = head;
            head = tmp;
        }
        ListNode *cur = head;
        while(cur != NULL){
            res.push_back(cur->val);
            cur = cur->next;
        }
        return res;
    }
};
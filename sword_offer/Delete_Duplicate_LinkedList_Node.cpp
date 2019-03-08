//
// Created by yzjhh on 2019/3/8.
//

/**
 *
 * 18.2 删除链表中重复的结点
 *
 * 题目描述：在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
 * 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 *
 *
 * note：这个题目要容易忽略同时出现两个以上重复元素的情况。
 * */


/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplication(ListNode *pHead) {
        if (pHead == NULL || pHead->next == NULL) {
            return pHead;
        }
        ListNode *preHead = new ListNode(-1);
        preHead->next = pHead;
        ListNode *pre = preHead;
        ListNode *cur = pre->next;
        ListNode *next = cur->next;
        int lastDeleted = pHead->val - 1; // 用一个变量来记录上一次被删除节点的值
        while (next != NULL) {
            if (cur->val == lastDeleted) { // 如果等于上次删除的节点值，那么删除当前节点
                cur = next;
                pre->next = cur;
            } else if (cur->val == next->val) { // 首先应该找到出现重复的节点，并标记当前节点的值，防止之后还重复出现该值
                lastDeleted = cur->val;
                cur = next->next;
                pre->next = cur;
            } else {
                pre = pre->next;
                cur = pre->next;
            }
            if (cur != NULL) {
                next = cur->next;
            } else {
                next = NULL; // 循环结束的条件为next不为空，但并不代表cur就一定就不为空
            }
        }
        if (cur != NULL && cur->val == lastDeleted) { // 针对上述cur不为空的情况，再次确认该cur是否与上次删除的元素重复
            pre->next = cur->next;
        }
        return preHead->next;
    }
};


int main() {
    Solution *solution = new Solution();
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(1);
    ListNode *l3 = new ListNode(1);
    ListNode *l4 = new ListNode(1);
    ListNode *l5 = new ListNode(1);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    ListNode *res = solution->deleteDuplication(l1);
    std::cout << "";
}
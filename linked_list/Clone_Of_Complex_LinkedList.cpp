//
// Created by yzjhh on 2019/4/10.
//

/**
 *
 * 复杂链表的复制
 *
 * */
#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;

    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode *Clone(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        // 在每个节点的后面插入一个一模一样的节点
        // 1->2->3->4->.... => 1->1'->2->2'->3->3'->4->4'->....
        RandomListNode *cur = head; // cur指向的是原链表的当前位置，如1、2、3、4...
        RandomListNode *new_cur; // new_cur指向的是复制链表的当前位置，如1'、2'、3'、4'...
        while (cur) {
            new_cur = new RandomListNode(cur->label);
            new_cur->next = cur->next;
            cur->next = new_cur;
            cur = new_cur->next;
        }

        // 仿照上一个节点对新加入节点的random进行赋值
        cur = head;
        while (cur) {
            new_cur = cur->next;
            new_cur->random = cur->random == NULL ? NULL : cur->random->next;
            cur = new_cur->next;
        }

        // 拆分链表，使得每个节点的next指向下个节点的next，例如 1->1'->2->2' => 1->2、1'->2'
        cur = head;
        RandomListNode *new_head = head->next;
        RandomListNode *next;
        while (cur->next) {
            next = cur->next;
            cur->next = next->next;
            cur = next;
        }
        return new_head;
    }
};
//
// Created by julyjohn on 2019-03-31.
//

/**
 *
 * 382. Linked List Random Node
 *
 * 题目描述：从链表中随机返回一个节点的值。
 *
 * note：此题的要点在于不能直接知道链表的长度，所以只能采用蓄水池算法，思想为：
 * 维护一个大小为k的蓄水池，对第i（i>k）个节点，随机生成一个在（0，i）中的数m，如果m小于k，那么就让m与i交换。
 * 蓄水池的大小是固定的，所以每个元素每次被替换的概率都是1/k
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int res = head->val;
        int i = 2; // i从2开始，相当于维护一个大小为1的水塘
        ListNode* cur = head->next;
        while(cur){
            int M = rand() % i;
            if(M == 0){
                res = cur->val;
            }
            cur = cur->next;
            ++i;
        }
        return res;
    }

private:
    ListNode* head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
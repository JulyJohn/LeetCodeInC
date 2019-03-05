//
// Created by yzjhh on 2019/3/5.
//

/**
 * 677. Map Sum Pairs
 *
 * Implement a MapSum class with insert, and sum methods.
 * For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value.
 * If the key already existed, then the original key-value pair will be overridden to the new one.
 * For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.
 *
 * 实现一个字典树前缀求和，要求输入相同的key时会覆盖上一次的val

Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
 * */

class TrieNode{
public:
    TrieNode *next[26];
    int val;
    bool is_word;

    TrieNode(int i = 0, bool b = false){
        memset(next, 0, sizeof(next));
        val = i;
        is_word = b;
    }
};

class MapSum {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        TrieNode *p = root;
        for(int i = 0; i < key.size() && p != NULL; i++){ // 首先看看key是否存在
            p = p->next[key[i] - 'a'];
        }
        if(p != NULL && p->is_word){ // 如果已经存在，则将上次的val给覆盖掉，即减去上一次该key产生的val再加上本次更新的val
            int old_val = p->val;
            TrieNode *rp = root;
            for(int i = 0; i < key.size(); i++){
                rp = rp->next[key[i] - 'a'];
                rp->val = rp->val -old_val + val;
            }
        }else{
            p = root;
            for(int i = 0; i < key.size(); i++){
                if(p->next[key[i] - 'a'] == NULL){
                    p->next[key[i] - 'a'] = new TrieNode(val);
                }else{
                    p->next[key[i] - 'a']->val += val;
                }
                p = p->next[key[i] - 'a'];
            }
            p->is_word = true;
        }
    }

    int sum(string prefix) {
        TrieNode *p = root;
        for(int i = 0; i < prefix.size() && p != NULL; i++){
            p = p->next[prefix[i] - 'a'];
        }
        return p != NULL ? p->val : 0;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
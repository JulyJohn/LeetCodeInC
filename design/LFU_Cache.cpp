//
// Created by yzjhh on 2019/3/19.
//

/**
 *
 * 460. LFU Cache
 *
 * Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.
 *
 * 题目描述：LFU是一种缓存机制，它规定距离当前最少被使用的数据应当被抛弃，而最常使用的数据应当位于缓存队列的头部
 *

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LFUCache cache = new LFUCache(2);// capacity

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.get(3);       // returns 3.
cache.put(4, 4);    // evicts key 1.
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
 * */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

class LFUCache {
public:
    LFUCache(int capacity) {
        cap_ = capacity;
        min_freq_ = -1;
    }

    int get(int key) {
        if (values_.count(key) == 0) {
            return -1;
        }
        Node &node = values_[key];
        freq_list_[node.freq].erase(node.iter);
        ++node.freq;
        freq_list_[node.freq].emplace_back(key);
        node.iter = --freq_list_[node.freq].end();
        if (freq_list_[min_freq_].size() == 0) {
            ++min_freq_;
        }
        return node.value;
    }

    void put(int key, int value) {
        if (cap_ <= 0) {
            return;
        }
        if (get(key) != -1) {
            values_[key].value = value;
            return;
        }
        if (values_.size() >= cap_) {
            auto &list = freq_list_[min_freq_];
            int evicted_key = list.front();
            list.pop_front();
            values_.erase(evicted_key);
        }
        min_freq_ = 1;
        auto &list = freq_list_[min_freq_];
        list.emplace_back(key);
        values_[key] = {value, min_freq_, --list.end()};

    }

private:
    int cap_;
    int min_freq_;
    struct Node {
        int value;
        int freq;
        list<int>::iterator iter;
    };
    unordered_map<int, Node> values_; // key - node
    unordered_map<int, list<int>> freq_list_; // freq list_keys
};

int main() {
    int capacity = 2;
    LFUCache *lruCache = new LFUCache(capacity);
    vector<int> nums = {};
    string s = "";
    return 0;
}
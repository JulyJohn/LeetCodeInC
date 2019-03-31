//
// Created by yzjhh on 2019/3/19.
//

/**
 *
 * 146. LRU Cache
 *
 * 题目描述：LRU是一种缓存机制，它规定距离当前最远没有使用的数据应当被抛弃，而最近使用的数据应当位于缓存队列的头部
 * */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;
class LRUCache {
private:
    int capacity;
    list<pair<int, int> > cacheQue; // 用于盛放缓存数据， 最大容量为capacity
    unordered_map<int, list<pair<int, int> >:: iterator> cacheMap; // 用于存放cacheQue中的Key的迭代器，方便查找O(1)
public:
    LRUCache(int capacity): capacity(capacity) {
    }

    int get(int key) {
        if(cacheMap.find(key) != cacheMap.end()){
            put(key, cacheMap[key]->second);
            return cacheMap[key]->second;
        }
        return -1;
    }

    void put(int key, int value) {
        if(cacheMap.find(key) != cacheMap.end()){ // 首先判断该key是否存在缓存队列中
            cacheQue.erase(cacheMap[key]); // 如果在，那么先从队列中移除掉
        }else if(cacheQue.size() >=  capacity){ // 接着判断cacheQue是不是满了
            cacheMap.erase(cacheQue.back().first); // 从cacheMap中移除cacheQue.end()
            cacheQue.pop_back(); // 从cacheQue中移除最后一个元素
        }
        cacheQue.push_front({key, value});
        cacheMap[key] = cacheQue.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    int capacity = 2;
    LRUCache *lruCache = new LRUCache(capacity);
    vector<int> nums = {};
    string s = "";
    return 0;
}
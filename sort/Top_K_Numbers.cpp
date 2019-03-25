//
// Created by yzjhh on 2019/3/25.
//

/**
 *
 * 题目描述：假设有十万个数字，统计出Top10词频的数字。
 *
 * */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void adjustHeap(vector<pair<int, int>> &a, int lo, int hi) {
    for (int cur = lo, next = cur * 2 + 1; next <= hi; cur = next, next = cur * 2 + 1) {
        if (next < hi && a[next + 1].second < a[next].second) {
            ++next;
        }
        if (a[next].second < a[cur].second) {
            pair<int, int> tmp_pair = a[next];
            a[next] = a[cur];
            a[cur] = tmp_pair;
        } else {
            break;
        }
    }
}

// 如果是ip，可以先将Ip转换成int
int ip2int(string ip) {
    string delimiter = ".";
    int res;
    int pos = 0;
    // 192.168.1.1
    int cnt = 3;
    while ((pos = ip.find(delimiter)) != string::npos) {
        res |= atoi(ip.substr(0, pos).c_str()) << (cnt << 3);
        ip.erase(0, pos + delimiter.length());
        --cnt;
    }
    res |= atoi(ip.c_str()) << (cnt << 3);
    return res;
}

int main() {
    int ip_int = ip2int("192.168.1.1");
    int k = 10;
    int loop_nums = 100000;
    unordered_map<int, int> map;
    vector<pair<int, int>> topKFreq(k, {INT32_MIN, 0});

    // generate numbers
    for (int i = 0; i < loop_nums; ++i) {
        srand((unsigned) time(0) + i);
        int num = rand() % 1000;
        if (map.find(num) == map.end()) {
            map.emplace(num, 1);
        } else {
            ++map[num];
        }
    }

    auto iter = map.begin();
    while (iter != map.end()) {
        if (iter->second > topKFreq[0].second) {
            topKFreq[0] = {iter->first, iter->second};
            adjustHeap(topKFreq, 0, k - 1);
        }
        ++iter;
    }

    cout << "==========================" << endl;
    for (int i = 0; i < k; ++i) {
        cout << topKFreq[i].first << ":" << topKFreq[i].second << endl;

    }

    return 0;
}
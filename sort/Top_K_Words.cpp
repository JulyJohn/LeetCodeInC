//
// Created by yzjhh on 2019/3/25.
//
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

/**
 *
 * 题目描述：假设有十万个单词，统计出Top10词频的单词。
 *
 * */

class TrieNode {
public:
    TrieNode *next[26];
    int word_freq;

    TrieNode() : word_freq(0) {
        memset(next, 0, sizeof(next));
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie(TrieNode *p) : root(new TrieNode()) {
        root = p;
    }

    /** insert a word into the trie **/
    int insert(string word) {
        TrieNode *p = root;
        for (char c : word) {
            if (p->next[c - 'a'] == NULL) {
                p->next[c - 'a'] = new TrieNode();
            }
            p = p->next[c - 'a'];
        }
        ++(p->word_freq);
        return p->word_freq;
    }

    /** search a word in the trie **/
    bool search(string word) {
        return findFreq(word) > 0;
    }

    /** find frequency of a word in the trie **/
    int findFreq(string word) {
        TrieNode *p = root;
        for (char c : word) {
            if (p == NULL) {
                break;
            }
            p = p->next[c - 'a'];
        }
        return p == NULL ? 0 : p->word_freq;
    }
};

// 小顶堆
void adjustHeap(vector<pair<string, int>> &a, int lo, int hi) {
    for (int cur = lo, next = cur * 2 + 1; next <= hi; cur = next, next = cur * 2 + 1) {
        if (next + 1 <= hi && a[next + 1].second < a[next].second) {
            ++next;
        }
        if (a[next].second < a[cur].second) {
            pair<string, int> tmp = a[cur];
            a[cur] = a[next];
            a[next] = tmp;
        } else {
            break;
        }
    }
}

string getRandomStr(int seed) {
    srand(seed);
    int str_len = rand() % 2 + 1;
    string str = "";
    for (int j = 0; j < str_len; ++j) {
        str.push_back((char) ('a' + rand() % 26));
    }
    return str;
}

int main() {
    int k = 10;
    int loop_nums = 100;
    vector<pair<string, int>> topKFreq(k, {"", 0});
    TrieNode *root = new TrieNode();
    Trie *word_tree = new Trie(root);

    // build trie
    for (int i = 0; i < loop_nums; ++i) {
        word_tree->insert(getRandomStr((unsigned) time(0) + i));
    }

    queue<pair<TrieNode *, string>> q;
    q.push({root, ""});
    while (!q.empty()) {
        int q_size = q.size();
        for (int i = 0; i < q_size; ++i) {
            pair<TrieNode *, string> tmp_pair = q.front();
            q.pop();
            TrieNode *tmp_node = tmp_pair.first;
            string cur_str = tmp_pair.second;
            if (tmp_node->word_freq > topKFreq[0].second) {
                topKFreq[0] = {cur_str, tmp_node->word_freq};
                adjustHeap(topKFreq, 0, k - 1);
            }
            for (int j = 0; j < 26; ++j) {
                if (tmp_node->next[j]) {
                    cur_str.push_back('a' + j);
                    q.push({tmp_node->next[j], cur_str});
                    cur_str.pop_back();
                }
            }
        }
    }

    cout << "==========================" << endl;
    for (int i = 0; i < k; ++i) {
        cout << topKFreq[i].first << ":" << topKFreq[i].second << endl;

    }

    return 0;
}
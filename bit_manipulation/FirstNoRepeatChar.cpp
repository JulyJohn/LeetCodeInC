//
// Created by yzjhh on 2019/4/9.
//

/**
 *
 * 字符流中第一个不重复的字符
 *
 * 题目描述：请实现一个函数用来找出字符流中第一个只出现一次的字符。
 *
 * */

class Solution
{
public:
    Solution():cnt(256, 0){
    }
    //Insert one char from stringstream
    void Insert(char ch)
    {
        ++cnt[ch];
        q.push(ch);
        while(!q.empty() && cnt[q.front()] > 1){
            q.pop();
        }
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        return q.empty() ? '#' : q.front();
    }

private:
    queue<char > q;
    vector<int > cnt;

};
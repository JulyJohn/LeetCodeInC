//
// Created by hejunhua on 19-1-18.
//

/**
 *
901. Online Stock Span
Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.
The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.
For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].
 题目大意：
 编写一个StockSpanner类用以收集一些股票的每日报价，并返回当天的股票报价跨度
　今日股票价格的跨度被定义为股票价格小于或等于今天价格的最大连续的天数（从今天开始到倒着往回数）。
　例如，如果未来 7 天股票的价格是 [100, 80, 60, 70, 60, 75, 85]，那么股票跨度将是 [1, 1, 1, 2, 1, 4, 6]。
Input: ["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
Output: [null,1,1,1,2,1,4,6]
Explanation:
First, S = StockSpanner() is initialized.  Then:
S.next(100) is called and returns 1,
S.next(80) is called and returns 1,
S.next(60) is called and returns 1,
S.next(70) is called and returns 2,
S.next(60) is called and returns 1,
S.next(75) is called and returns 4,
S.next(85) is called and returns 6.
Note that (for example) S.next(75) returned 4, because the last 4 prices
(including today's price of 75) were less than or equal to today's price.
 *
 * */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> prices_idx;

    StockSpanner() {
    }

    int next(int price) {
        int ans = 1;
        while(!prices_idx.empty() && prices_idx.top().first <= price){
            ans += prices_idx.top().second;
            prices_idx.pop();
        }
        prices_idx.push({price, ans});
        return ans;
    }
};

//class StockSpanner {
//public:
//    vector<int> prices;
//    int idx;
//    stack<int> s;
//
//    StockSpanner() {
//        prices.clear();
//        idx = 0;
//    }
//
//    int next(int price) {
//        int ans;
//        while (!s.empty() && prices[s.top()] <= price)
//            s.pop();
//        if (s.empty())
//            ans = idx + 1;
//        else
//            ans = idx - s.top();
//
//        prices.push_back(price);
//        s.push(idx);
//
//        idx++;
//        return ans;
//    }
//};

int main() {
    StockSpanner *ss = new StockSpanner();
    vector<int> input_data = {100, 80, 60, 70, 60, 75, 85};
    for (int i = 0; i < input_data.size(); ++i) {
        int ans = ss->next(input_data[i]);
        cout << ans << ",";
    }
}
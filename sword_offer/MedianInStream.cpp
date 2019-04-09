//
// Created by yzjhh on 2019/4/9.
//
/**
 *
 * 数据流中的中位数
 *
 * 题目描述：如何得到一个数据流中的中位数？
 * 如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
 * 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
 * 我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
 *
 * note：维护两个堆，使得右边小顶堆的元素都大于左边大顶堆的元素，并且左边元素的个数，要么与右边相等（偶数次输入），要么比右边大1（奇数次输入）
 *
 * */

class Solution {
public:
    void Insert(int num)
    {
        if(left.empty() || num <= left.top()){
            left.push(num);
        }else{
            right.push(num);
        }
        // 左边大顶堆的大小最多可以比右边小顶堆大1（奇数次输入）
        if(left.size() == right.size() + 2){
            right.push(left.top());
            left.pop();
        }
        // 因为最后返回的只有可能是左边大顶堆的堆顶，所以右边小顶堆的大小不能比左边小顶堆大
        if(left.size() + 1 == right.size()){
            left.push(right.top());
            right.pop();
        }
    }

    double GetMedian()
    {
        return left.size() == right.size() ? (left.top() + right.top())/2. : left.top();
    }
private:
    // 右边小顶堆的元素都大于左边大顶堆的元素，并且左边元素的个数，要么与右边相等（偶数次输入），要么比右边大1（奇数次输入）
    priority_queue<int, vector<int>, less<int> > left; // 大顶堆
    priority_queue<int, vector<int>, greater<int> > right; // 小顶堆
};
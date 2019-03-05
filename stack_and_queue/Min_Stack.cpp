//
// Created by yzjhh on 2019/3/5.
//

/**
 *
 * 155. Min Stack
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * 题目描述：设计一个最小值栈。

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
 *
 * */

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    stack<int> dataStack;
    stack<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (minStack.empty() || getMin() >= x) { // 注意这里的等号
            minStack.push(x);
        }
        dataStack.push(x);
    }

    void pop() {
        if (top() == getMin()) {
            minStack.pop();
        }
        dataStack.pop();
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
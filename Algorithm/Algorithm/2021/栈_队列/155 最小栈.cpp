//
//  155 最小栈.cpp
//  Algorithm
//
//  Created by zack on 2021/2/15.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
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
        dataStack.push(x);
        if (minStack.size() == 0) {
            minStack.push(x);
        } else {
            int min = minStack.top();
            if (min > x) {
                minStack.push(x);
            } else {
                minStack.push(min);
            }
        }
    }
    
    void pop() {
        dataStack.pop();
        minStack.pop();
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
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

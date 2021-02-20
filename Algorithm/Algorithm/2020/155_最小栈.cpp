//
//  155_最小栈.cpp
//  Algorithm
//
//  Created by zack on 2020/5/22.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<int> sta;
    stack<int> minSta;
    
    MinStack() {
    }
    
    void push(int x) {
        sta.push(x);
        
        if(minSta.empty()){
            minSta.push(x);
        }else{
            int top = minSta.top();
            if (x < top) {
                minSta.push(x);
            } else {
                minSta.push(top);
            }
        }
    }
    
    void pop() {
        sta.pop();
        minSta.pop();
    }
    
    int top() {
        return sta.top();
    }
    
    int getMin() {
        return minSta.top();
    }
};

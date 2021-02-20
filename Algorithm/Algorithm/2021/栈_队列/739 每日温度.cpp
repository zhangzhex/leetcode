//
//  739 每日温度.cpp
//  Algorithm
//
//  Created by zack on 2021/2/16.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    /*
    //1. 维护一个栈，要求栈元素从底至顶增大的顺序
    //2. 遍历数组，栈顶元素小于当前值则出栈，该当前值为右边第一个大于栈顶元素的值
    //3. 栈顶元素大于等于当前值则入栈
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(), 0);
        stack<int> st;
        
        for (int i = 0; i < T.size(); i++) {
            while (st.size() > 0 && T[st.top()] < T[i]) {
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
    */
    
    //解法2：倒推法
    //1. 两个指针i,j 其中j为最后一个索引，j=i+1，开始向前遍历
    //1.1 如果T[i] < T[j], 则result[i] = j-i;
    //1.2 如果T[i] >= T[j], 如果T[j]=0,则T[i] = 0,否则一直重复j=j+result[j]
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(), 0);
//        if (T.size() < 2) return result;
        
        for (int i = (int)T.size()-2; i>=0; i--) {
            int j = i+1;
            while (true) {
                if (T[i] < T[j]) {
                    result[i] = j-i;
                    break;
                } else if(T[j] == 0) {
                    result[i] = 0;
                    break;
                }
                j = j+result[j];
            }
        }
        
        return result;
    }
    
};


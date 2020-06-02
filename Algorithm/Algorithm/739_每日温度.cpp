//
//  739_每日温度.cpp
//  Algorithm
//
//  Created by zack on 2020/6/2.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     *思路：1、使用栈数据结构，栈始终保持递减(栈底->栈顶)
     *2、如果一个元素入栈说明栈顶元素小于本身，一个元素出栈说明该元素小于准备入栈元素(第一个大于自身的元素)
     *3、栈存放索引值
     *
     */
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.size() == 0) {
            return T;
        }
        
        stack<int> sta;
        vector<int> vec(T.size());
        for (int i = 0; i < T.size(); i++) {
            vec[i] = 0;
            int value = T[i];
            while (sta.size() > 0) {
                if (T[sta.top()] < value) {
                    vec[sta.top()] = i - sta.top();
                    sta.pop();
                }
            }
            sta.push(i);
        }
        return vec;
    }
};

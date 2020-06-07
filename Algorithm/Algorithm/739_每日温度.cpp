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
     *思路：使用栈数据结构，栈始终保持递减(栈底->栈顶)，栈存放的数据是索引值
     *1、如果一个元素能入栈说明栈顶元素大于本身
     *2、一个元素出栈说明该元素小于准备入栈元素(第一个大于自身的元素)，遍历栈元素直到入栈
     *
     */
//    vector<int> dailyTemperatures(vector<int>& T) {
//        if (T.size() == 0) {
//            return T;
//        }
//
//        stack<int> sta;
//        vector<int> vec(T.size());
//        for (int i = 0; i < T.size(); i++) {
//            vec[i] = 0;
//            int value = T[i];
//            while (sta.size() > 0) {
//                if (T[sta.top()] < value) {
//                    vec[sta.top()] = i - sta.top();
//                    sta.pop();
//                }
//            }
//            sta.push(i);
//        }
//        return vec;
//    }
        
    /**
     * 思路：利用动态规划思想从最后一天(永远是0)倒推前面数据
     * 1、创建两个索引，默认i=length-2,j=length-1，开始从尾到头遍历
     * 1.1 当T[i] < T[j],则vec[i] = j-i;
     * 1.2 当T[i] == T[j],则vec[i] = vec[j] + j-i;
     * 1.3 当T[j] > T[j], 如果T[j]==0,则T[i] = 0, 否则 j=j+vec[j]，继续重复上面两步判断
     */
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.size() == 0) {
            return T;
        }
        vector<int> vec(T.size());
        vec[T.size()-1] = 0;
        for (int i = (int)T.size()-2; i >= 0; i--) {
            int j = i + 1;
            while (true) {
                 if (T[i] < T[j]) {
                     vec[i] = j - i;
                     break;
                 } else if (vec[j] == 0) {  // 提前判断，因为T[i] == T[j]情况下，存在vec[j] == 0
                     vec[i] = 0;
                     break;
                 } else if (T[i] == T[j]) {
                     vec[i] = vec[j] + j-i;
                     break;
                 } else {
                     j = j + vec[j];
                 }
             }
        }
        
        return vec;
    }
};

//
//  239_滑动窗口最大值.cpp
//  Algorithm
//
//  Created by zack on 2020/5/25.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     *思路：
     *1. 引入双端队列数据结构，存储元素为索引值，要求队列元素索引对应的值为降序
     *2. 定义两个索引变量head,tail， head - tail + 1 = 滑动窗口宽度
     *3. head=0开始遍历数组。
     *  3.1 如果head索引对应的值大于队尾元素对应值，则弹出队尾元素，循环判断。否则加入队尾
     *  3.2 判断tail索引是否合法，如果合法校验队头元素是否在滑动窗口内，同时队头元素为当前最大值
     */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> vec;
        
        if (k == 0 || nums.size() == 0) {
            return vec;
        }
        
        if (nums.size() == 1) {
            return nums;
        }
        
        deque<int> dequ;
        int head = 0;
        
        while (head < nums.size()) {
            while (!dequ.empty() && nums[dequ.back()] <= nums[head]) {
                dequ.pop_back();
            }
            dequ.push_back(head);
            
            int tail = head - k + 1;
            if (tail >= 0) {
                if (dequ.front() < tail) {
                    dequ.pop_front();
                }
                vec.push_back(nums[dequ.front()]);
            }
            
            head++;
        }
        return vec;
    }
};

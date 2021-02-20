//
//  239 滑动窗口最大值.cpp
//  Algorithm
//
//  Created by zack on 2021/2/15.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    //1. 使用双端队列，存储数组元素索引，要求队列存储的索引对应元素值为递减顺序
    //2. 索引i、j指向窗口头尾，i=0，j=0-k+1，开始遍历数组
    //3. 每遍历一个值x，加入队列前，遍历队列尾部元素值比x小则出队列
    //4. 比较队列首元素是否小于j，小于则移除
    //5. 每一次i移动，把队列首元素放入结果数组里
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;
        vector<int> result;
        deque<int> deq;
        int j = 1-k;
        for (int i = 0; i < nums.size(); i++) {
            int v = nums[i];
            bool insertIndex = false;
            // 队列添加数组元素索引
            while (insertIndex == false) {
                if (deq.size() == 0) {
                    deq.push_back(i);
                    insertIndex = true;
                } else {
                    int last = nums[deq.back()];
                    if (last <= v) {
                        deq.pop_back();
                    } else {
                        deq.push_back(i);
                        insertIndex = true;
                    }
                }
            }
            // 队列首元素是否合法
            if (deq.front() < j) {
                deq.pop_front();
            }
            // 结果数组添加元素
            if (j >= 0) {
                result.push_back(nums[deq.front()]);
            }
            j++;
        }
        return result;
    }
};

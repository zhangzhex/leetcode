//
//  42 接雨水.cpp
//  Algorithm
//
//  Created by zack on 2021/2/16.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> leftMax(height.size(), 0);
        //每个元素左边最大值
        for (int i = 1; i < height.size(); i++) {
            leftMax[i] = max(leftMax[i-1], height[i-1]);
        }
        
        vector<int> rightMax(height.size(), 0);
        //每个元素右边最大值
        for (int i = (int)height.size() - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i+1]);
        }
        
        //左右最大值中较小的为水平面，每个元素蓄水 = 水平面 - 元素值
        int water = 0;
        for (int i = 0; i < height.size(); i++) {
            int level = min(leftMax[i], rightMax[i]);
            water += max(0, level - height[i]);
        }
        
        return water;
    }
};

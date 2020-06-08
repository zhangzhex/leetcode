//
//  42_接雨水.cpp
//  Algorithm
//
//  Created by zack on 2020/6/8.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     *思路：和739题类似，
     *1、先分别求出每个元素左右两边的最大值
     *2、取每个元素左右最大值中较低的作为水平面值
     *3、遍历数组，元素水平面值 - 元素本身大小 = 每个元素能蓄水量
     */
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        
        vector<int> leftMaxVec(height.size());
        vector<int> rightMaxVec(height.size());
        
        for (int i = 1; i < height.size(); i++) {
            leftMaxVec[i] = max(leftMaxVec[i-1], height[i-1]);
        }
        
        for (int i = (int)height.size() - 2; i >=0; i--) {
            rightMaxVec[i] = max(rightMaxVec[i+1], height[i+1]);
        }
        
        int water = 0;
        for (int i = 0; i < height.size(); i++) {
            int level = min(leftMaxVec[i], rightMaxVec[i]);
            water += max(0, level - height[i]);
        }
        
        return water;
    }
};

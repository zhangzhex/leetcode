//
//  面试题 16_16 部分排序.cpp
//  Algorithm
//
//  Created by zack on 2020/4/18.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    //思路：1、从左向右遍历，找出逆序索引，记录最大值，
    // 2、从右向左遍历，找出逆序索引，记录最小值
    vector<int> subSort(vector<int>& array) {
        
        if (array.size() == 0) {
            vector<int> vec {-1, -1};
            return vec;
        }
        
        int max = array[0];
        int rightIndex = -1;
        for (int i = 1; i < array.size(); i++) {
            int v = array[i];
            if (v >= max) {
                max = v;
            } else {
                rightIndex = i;
            }
        }
        
        if (rightIndex == -1) {
            vector<int> vec {-1, -1};
            return vec;
        }
        
        int min = array[array.size() - 1];
        int leftIndex = -1;
        for (int i = (int)array.size() - 2; i >= 0; i--) {
            int v = array[i];
            if (v <= min) {
                min = v;
            } else {
                leftIndex = i;
            }
        }
        
        vector<int> vec {leftIndex, rightIndex};
        return vec;
    }
};

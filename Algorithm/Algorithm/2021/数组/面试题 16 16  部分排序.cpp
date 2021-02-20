//
//  面试题 16 16  部分排序.cpp
//  Algorithm
//
//  Created by zack on 2021/2/14.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        if (array.size() == 0) return vector<int> {-1, -1};
            
        //从左往右找最远逆序
        int max = array[0];
        int r = -1;
        for (int i = 1; i < array.size(); i++) {
            int v = array[i];
            if (v >= max) {
                max = v;
            } else {
                r = i;
            }
        }
        
        //从右往左找最远逆序
        int min = array[array.size()-1];
        int l = -1;
        for (int i = (int)array.size()-2; i >= 0; i--) {
            int v = array[i];
            if (v <= min) {
                min = v;
            } else {
                l = i;
            }
        }
        
        return vector<int> {l, r};
    }
};

//
//  283 移动零.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2021/3/14.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 2) return;
        // 移动非0元素至队头
        int index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (index == -1) {
                    index = i;
                }
            } else {
                if (index >= 0) {
                    nums[index] = nums[i];
                    nums[i] = 0;
                    index++;
                }
            }
        }
    }
};

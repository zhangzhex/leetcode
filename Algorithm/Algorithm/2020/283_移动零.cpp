//
//  283_移动零.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2020/7/26.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 思路:移动非0的数元素，zeroIndex表示0元素的位置，当遍历到非0元素时，交换两个元素位置
     */
    void moveZeroes(vector<int>& nums) {
        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) continue;
            // 非0元素且curr索引不同时，才做交换
            if (i != curr) {
                nums[curr] = nums[i];
                nums[i] = 0;
            }
            curr++;
        }
    }
};

//
//  75_颜色分类.cpp
//  Algorithm
//
//  Created by zack on 2020/4/11.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    // 0、 1 和 2 分别表示红色、白色和蓝色
    //思路：三指针，红色Pointer指向头,蓝色Pointer指向尾, 白色Pointer从头开始遍历,
    //如果白色Pointer的值是0，和红色Pointer的值交换，白色Pointer++，红色Pointer++
    //如果白色Pointer的值是1，白色Pointer++
    //如果白色Pointer的值是2,和蓝色Pointer的值交换，蓝色Pointer--
    
    void sortColors(vector<int>& nums) {
        
        int redIndex = 0;
        int whiteIndex = 0;
        int blueIndex = (int)nums.size() - 1;
        
        while (whiteIndex <= blueIndex) {
            int currValue = nums[whiteIndex];
            if (currValue == 0) {
                int redValue = nums[redIndex];
                nums[redIndex] = currValue;
                nums[whiteIndex] = redValue;
                redIndex ++;
                whiteIndex ++;
            } else if (currValue == 1) {
                whiteIndex ++;
            } else {
                int blueValue = nums[blueIndex];
                nums[blueIndex] = currValue;
                nums[whiteIndex] = blueValue;
                blueIndex--;
            }
        }
    }
};

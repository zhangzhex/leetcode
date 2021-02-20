//
//  75 颜色分类.cpp
//  Algorithm
//
//  Created by zack on 2021/2/13.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int leftIndex = 0;
        int rightIndex = (int)nums.size() - 1;
        int currIndex = 0;
        
        while (currIndex <= rightIndex) {
            int value = nums[currIndex];
            if (value == 0) {
                swap(nums, leftIndex, currIndex);
                leftIndex++;
                currIndex++;
            } else if (value == 1) {
                currIndex++;
            } else {
                swap(nums, currIndex, rightIndex);
                rightIndex--;
            }
        }
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

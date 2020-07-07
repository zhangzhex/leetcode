//
//  674_最长连续递增序列.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2020/7/7.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     *思路：递推&动态规划
     *1、dp[i] 表示以第i个元素结尾的递增序列长度
     *2、if(nums[i] > dp[i-1]) dp[i] = dp[i-1]+1，否则dp[i] = 1
     */
    int findLengthOfLCIS(vector<int>& nums) {
        int length = (int)nums.size();
        if (length < 2) {
            return length;
        }
        
        int pre = 1;
        int maxLength = pre;
        for (int i = 1; i < length; i++) {
            int curr = 0;
            if (nums[i] > nums[i-1]) {
                curr = pre + 1;
            } else {
                curr = 1;
            }
            pre = curr;
            maxLength = max(maxLength, curr);
        }
        
        return maxLength;
    }
};

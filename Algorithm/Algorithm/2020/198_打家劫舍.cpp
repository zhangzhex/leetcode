//
//  198_打家劫舍.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2020/7/6.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    /**
     * 思路：动态规划
     * 1、dp[i] 表示第i天偷取的最大金额
     * 2、 dp[i] =  max(dp[i-1], dp[i-2] + nums[i]);
     */
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[nums.size()-1];
    }
};

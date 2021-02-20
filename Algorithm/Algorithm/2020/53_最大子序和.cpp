//
//  53_最大子序和.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2020/7/3.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     *思路：动态规划
     *1. dp[i]表示以nums[i]结尾的数组最大值
     *2. 状态转移方程
     *  2.1 如果dp[i-1]  >  0   则 dp[i] = dp[i-1] + nums[i];
     *  2.2 如果dp[i-1]  <= 0  则 dp[i] =  nums[i];
     *3. 遍历一遍数据，得到一个最大值
     */
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int dp = nums[0];
        int maxValue = dp;
        for (int i = 1; i < nums.size(); i++) {
            if (dp > 0) {
                dp = dp + nums[i];
            } else {
                dp = nums[i];
            }
            maxValue = max(dp, maxValue);
        }
        return maxValue;
    }
};

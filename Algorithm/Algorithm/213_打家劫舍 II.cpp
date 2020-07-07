

//
//  213_打家劫舍 II.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2020/7/7.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        
        vector<int> dp(nums.size());
        int result = 0;
        // 第一天抢
        dp[0] = nums[0];
        dp[1] = dp[0];
        for (int i = 2; i < nums.size(); i++) {
            //最后一天一定不能抢
            if (i == nums.size()-1) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            }
        }
        result = dp[nums.size()-1];
        
        // 第一天不抢
        dp[0] = 0;
        dp[1] = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        
        return max(dp[nums.size()-1], result);
    }
};


//
//  300_最长上升子序列.cpp
//  Algorithm
//
//  Created by zack on 2020/7/4.
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
     *1、定义状态，dp[i]表示以索引为i元素结尾的最长上升子序列的长度
     *2、状态转移方程
     *  2.1、遍历dp[0]到dp[i-1]
     *      2.2、如果nums[j] < nums[i]，得到(dp[j] + 1)的最大值
     */
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int maxLength = 1;
        vector<int> dp(nums.size());
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            int length = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    length = max(length, dp[j] + 1);
                }
            }
            dp[i] = length;
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }
};

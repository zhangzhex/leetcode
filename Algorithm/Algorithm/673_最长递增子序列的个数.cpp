//
//  673_最长递增子序列的个数.cpp
//  Algorithm
//
//  Created by zack on 2020/7/11.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     *思路：动态规划思想
     *1、状态定义，dp[i]表示以nums[i]结尾的最长递增数组长度，count[i]表示以nums[i]结尾的最长递增数组个数
     *2、状态转移方程
     *  2.1 遍历数组dp，计算每一个元素结尾的最大值dp[i]
     *  2.2
     */
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() < 2) {
            return (int)nums.size();
        }
        
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);
        
        int maxLength = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[j] + 1 > dp[i]) {// 重新得到一个新的最大长度
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }else if (dp[j] + 1 == dp[i]) {// 得到另一组同样的最大长度
                        count[i] += count[j];
                    }
                }
                maxLength = max(maxLength, dp[i]);
            }
        }
        
        int maxCount = 0;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i] == maxLength) {
                maxCount += count[i];
            }
        }
        return maxCount;
    }
};

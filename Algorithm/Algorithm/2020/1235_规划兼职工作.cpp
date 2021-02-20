//
//  1235_规划兼职工作.cpp
//  Algorithm
//
//  Created by zack on 2020/7/11.
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
     *1、状态定义dp[i] 表示i时间结尾，获得的最大报酬
     *2、状态转移方程
     *  2.1  dp[i] = max(dp[j] + profit[j][i])，其中j = [0, i), profit[j][i]表示以j开始并以i结束的某一个工作利润，如果没有工作符合该时间，则为0
     */
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        if (startTime.size() == 0 || endTime.size() == 0 || profit.size() == 0) {
            return 0;
        }
        
        int maxStart = 0;
        for (int i = 0; i < startTime.size(); i++) {
            maxStart = max(startTime[i], maxStart);
        }
        int maxProfit = 0;
        vector<int>dp(maxStart + 1);
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j < i; j++) {
                // 查找匹配[j i]的工作
                int jobProfit = 0;
                for (int k = 0; k < startTime.size(); k++) {
                    if (startTime[k] == j && endTime[k] == i) {
                        jobProfit = max(jobProfit, profit[k]);
                    }
                }
                dp[i] = max(dp[i], dp[j] + jobProfit);
            }
            maxProfit = max(dp[i], maxProfit);
        }
        
        return maxProfit;
    }
};


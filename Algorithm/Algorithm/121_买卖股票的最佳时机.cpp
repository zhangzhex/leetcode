//
//  121_买卖股票的最佳时机.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2020/6/21.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    /**
     *思路：动态规划思想，股票买入卖出产生的利润 = 从买入那天到卖出那天之间每天的股价差之和，即求最大连续子序列合问题
     */
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        
        vector<int> value = vector<int>(prices.size() - 1);
        int pre = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            value.push_back(prices[i] - pre);
            pre = prices[i];
        }
        
        int dp = value[0];
        int profit = dp;
        for (int i = 1; i < value.size(); i++) {
            if (dp > 0) {
                dp = dp + value[i];
            } else {
                dp = value[i];
            }
            profit = max(dp, profit);
        }
        return profit;
    }
    
    /**
     *思路：
     *1、第一个元素当做最小值，初始化最大利润为0
     *2、遍历数组元素，当前值大于最小值，更新最大利润
     *2.1、当前值小于最小值，则把当前值设置为最小值
     *
     */
    /*
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        
        int min = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > min) {
                maxProfit = max(prices[i] - min, maxProfit);
            } else {
                min = prices[i];
            }
        }
        return maxProfit;
    }*/
};

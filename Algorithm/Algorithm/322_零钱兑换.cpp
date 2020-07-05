//
//  322_零钱兑换.cpp
//  Algorithm
//
//  Created by zack on 2020/6/26.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    /**
     *思路：递推思想，从总额=1开始计算所需硬币个数，逐个推导出总额=amount时所需硬币个数
     *1. dp[i] 表示凑成总额i时最少硬币个数
     *2. 状态转移方程, 假设硬币面额有 1、5、10
     *  2.1 dp[i] = min(dp[i - 1], dp[i - 5], dp[i - 10]) + 1
     */
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (coins.size() == 0) {
            return -1;
        }
        
        vector<int> dp = vector<int>(amount+1);  //每个数组元素表示凑成总金额dp[i]所需的最少的硬币个数
        for (int i = 1; i <= amount; i++) {
            int min = INT_MAX;
            for (int j = 0; j < coins.size(); j++) {
                if (i < coins[j] || dp[i - coins[j]] < 0 || dp[i - coins[j]] >= min) continue;
                min = dp[i - coins[j]];
            }
            
            if (min == INT_MAX) {
                dp[i] = -1;
            } else {
                dp[i] = min + 1;
            }
        }
        
        return dp[amount];
    }
};

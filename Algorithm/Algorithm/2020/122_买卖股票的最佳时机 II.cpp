//
//  122_买卖股票的最佳时机 II.cpp
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
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        
        vector<int> dp(prices.size()-1);
        for (int i = 1; i < prices.size(); i++) {
            dp[i-1] = prices[i] - prices[i-1];
        }
        
        int profit = 0;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i] > 0) {
                profit += dp[i];
            }
        }
        
        return profit;
    }
};

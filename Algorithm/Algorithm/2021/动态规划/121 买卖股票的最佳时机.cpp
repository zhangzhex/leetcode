//
//  121 买卖股票的最佳时机.cpp
//  Algorithm
//
//  Created by zack on 2021/2/21.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int profit = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                profit = max(prices[i] - minPrice, profit);
            }
        }
        return profit;
    }
};

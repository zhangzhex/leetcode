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
     *思路：1、第一个元素当做最小值，最大利润为0
     *2、遍历数组元素，当前值大于最小值，更新最大利润
     *2.1、当前值小于最小值，则把当前值设置为最小值
     *
     */
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
    }
};

//
//  面试题 08_11_硬币.cpp
//  Algorithm
//
//  Created by zack on 2020/7/4.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     *思路：动态规划思想
     *1、定义状态dp[i] i分钱有多少总分法
     *2、状态转移方程
     *  2.1 遍历tokens, 得到tokens[i]
     *      2.1.1 从i=1到n遍历， dp[i] = (dp[i] + dp[i-tokens[i]])
     *  2.1 经过tokens.size()次外循环遍历，每个i分钱的分法包含了所有币值的情况
     */
    int waysToChange(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        vector<int> tokens = {1,5,10,25};
        int mod = 1000000007;
        
        for(int i = 0; i < tokens.size(); i++){
            int money = tokens[i];
            for(int j = 1; j <= n; j++){
                if(j < money) continue;
                dp[j] = (dp[j] + dp[j-money]) % mod;
            }
        }
        
        return dp[n];
    }
};

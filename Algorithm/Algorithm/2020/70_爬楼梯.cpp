//
//  70_爬楼梯.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2020/7/6.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     *思路：递推思想（动态规划）
     *1、dp[i] 表示爬 i个台阶的方法
     *2、dp[i] = dp[i-1] + dp[i-2]
     */
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        
        int first = 1;
        int second = 2;
        
        for (int i = 3; i <= n; i++) {
            int temp = first + second;
            first = second;
            second = temp;
        }
        return second;
    }
};

//
//  剑指 Offer 47 礼物的最大价值.cpp
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
    int maxValue(vector<vector<int>>& grid) {
        /*
        动态规划
        1. m行n列，确定第一行、第一列的值
        2. 其余格子，最大值 = max(上面格子，左边格子) + 本身值
         */
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        vector<vector<int>> result(m);
        for (int i = 0; i < m; i++) {
            result[i].resize(n);
        }
        
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                result[0][i] = grid[0][i];
            } else {
                result[0][i] = grid[0][i] + result[0][i-1];
            }
        }
        
        for (int i = 0; i < m; i++) {
            if (i == 0) {
                result[i][0] = grid[i][0];
            } else {
                result[i][0] = grid[i][0] + result[i-1][0];
            }
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                result[i][j] = max(result[i-1][j], result[i][j-1]) + grid[i][j];
            }
        }
        
        return result[m-1][n-1];
    }
};

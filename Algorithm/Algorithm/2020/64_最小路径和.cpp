//
//  64_最小路径和.cpp
//  Algorithm
//
//  Created by zack on 2020/6/28.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     *思路：动态规划思想，得到动态转义方程dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]，再使用一维数组优化空间复杂度
     */
    int minPathSum(vector<vector<int>>& grid) {
        uint64_t row = grid.size();
        uint64_t col = grid[0].size();
        
        vector<int> dp(col+1, 0);
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                int m = min(dp[j], dp[j-1]);
                if (j == 1){
                    m = dp[j];
                }
                if (i == 1){
                    m = dp[j-1];
                }
                dp[j] = m + grid[i-1][j-1];
            }
        }
        
        return dp[col];
    }
};

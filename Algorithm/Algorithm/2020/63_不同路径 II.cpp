//
//  63_不同路径 II.cpp
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
    /**
     *思路：动态规划
     *定义状态，dp[i][j]表示走到i行j列的路径数
     *状态转移方程，
     * 如果obstacleGrid[i][j] == 1， dp[i][j] = 0; 否则dp[i][j] = dp[i-1][j] + dp[i][j-1]
     *
     */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            if (obstacleGrid.size() == 0 || obstacleGrid[0][0] == 1) {
                return 0;
            }
            int row = (int)obstacleGrid.size();
            int col = (int)obstacleGrid[0].size();
            
            vector<vector<int>> dp(row, vector<int>(col));
            dp[0][0] = 1;
            //初始化第0行
            for (int i = 1; i < col; i++) {
                if (obstacleGrid[0][i] == 1) break;
                dp[0][i] = 1;
            }
            
            //初始化第0列
            for (int i = 1; i < row; i++) {
                if (obstacleGrid[i][0] == 1) break;
                dp[i][0] = 1;
            }
            
            for (int i = 1; i < row; i++) {
                for (int j = 1; j < col; j++) {
                    if (obstacleGrid[i][j] == 1) {
                        dp[i][j] = 0;
                    } else {
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }
                }
            }
            
            return dp[row-1][col-1];
    }
};

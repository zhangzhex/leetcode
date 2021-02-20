//
//  72_编辑距离.cpp
//  Algorithm
//
//  Created by zack on 2020/6/28.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     *思路：最...问题动态规划思想
     *1、定义状态：dp[i][j]（i，j分别为两字符串长度）表示word1[0, i)转换成word2[0, j)最少操作数
     *2、状态转移方程
     *  2.1 插入操作，dp[i][j] = dp[i-1][j] + 1
     *  2.2 删除操作，dp[i][j] = dp[i][j-1] + 1
     *  2.3 替换操作，如果最后一个字符不相同dp[i][j] = dp[i-1][j-1] + 1，否则dp[i][j] = dp[i-1][j-1]
     */
    int minDistance(string word1, string word2) {
        if (word1.size() == 0) {
            return (int)word2.size();
        }
        if (word2.size() == 0) {
            return (int)word1.size();
        }
        int row = (int)word1.size();
        int col = (int)word2.size();
        
        //创建二维数组，状态转义表
        vector<vector<int>> dp(row+1, vector<int>(col+1));
        //初始化第0行，第0列数据
        for (int i = 0; i <= row; i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= col; i++) {
            dp[0][i] = i;
        }
        
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                int insert = dp[i-1][j] + 1;
                int remove = dp[i][j-1] + 1;
                int rep = dp[i-1][j-1];
                if (word1[i-1] != word2[j-1]) {
                    rep++;
                }
                dp[i][j] = min(min(insert, remove), rep);
            }
        }
        
        return dp[row][col];
    }
};

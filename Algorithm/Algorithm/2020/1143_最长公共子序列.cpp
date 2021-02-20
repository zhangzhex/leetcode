//
//  1143_最长公共子序列.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2020/7/1.
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
     * 1、定义状态 dp[i][j] = string1[0, i) 与 string2[0, j)最长公共子序列的长度
     * 2、状态转移方程，状态转移表：vector[string1.size()+1][string2.size()+1]
     *  2.1 如果string[i] == string2[j]， dp[i][j] = dp[i-1][j-1] + 1，否则dp[i][j] = max(dp[i-1][j]， dp[i][j-1])
     */
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() == 0 || text2.size() == 0) {
            return 0;
        }
        // 状态转移表[0][0] 字符串为空的情况,行、列 = 字符串长度+1
        int row = (int)text1.size() + 1;
        int col = (int)text2.size() + 1;
        vector<vector<int>> dp(row, vector<int>(col));
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] =  dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[row-1][col-1];
    }
};

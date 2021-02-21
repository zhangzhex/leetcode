//
//  72  编辑距离.cpp
//  Algorithm
//
//  Created by zack on 2021/2/21.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        /*
        1. 定义状态转移表，dp[i][j]表示word1子串[0 i)转换成word2子串[0 j)需要的最小操作数
        2. 初始化dp[0][0] - dp[0][j], dp[0][0] - dp[i][0]
        3. 状态转移方程：
            3.1 通过删除最后一个元素完成操作，dp[i][j] = dp[i][j-1] + 1
            3.2 插入最后一个元素完成操作，dp[i][j] = dp[i-1][j] + 1
            3.3 修改最后一个元素，如果 word1[i-1] == word2[j-1], dp[i][j] = dp[i-1][j-1]；否则dp[i][j] = dp[i-1][j-1] + 1
         */
        int row = (int)word1.size()+1;
        int col = (int)word2.size()+1;
        vector<vector<int>> result(row);
        for (int i = 0; i < result.size(); i++) {
            result[i].resize(col);
        }
        
        for (int i = 0; i < row; i++) {
            result[i][0] = i;
        }
        
        for (int i = 0; i < col; i++) {
            result[0][i] = i;
        }
        
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (word2[j-1] == word1[i-1]) {
                    result[i][j] = min(result[i-1][j-1], min(result[i-1][j]+1, result[i][j-1]+1));
                } else {
                    result[i][j] = min(result[i-1][j-1]+1, min(result[i-1][j]+1, result[i][j-1]+1));
                }
            }
        }
        
        return result[row-1][col-1];
    }
};

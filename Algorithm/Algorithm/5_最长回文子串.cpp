//
//  5_最长回文子串.cpp
//  Algorithm
//
//  Created by zack on 2020/6/28.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     *思路：最...问题动态规划思想
     *1、定义状态：dp[i][j]表示字符串string[i, j]是否为回文子串
     *2、状态转移方程，状态转移表为行列长度均为string.length的二维数组
     *  2.1 如果子串长度<=2, 如果string[i]==string[j]，则dp[i][j]为回文子串
     *  2.1 如果长度>2, 如果string[i]==string[j] && dp[i+1][j-1]为回文子串，则dp[i][j]为回文子串
     *
     * 遍历二维数组生成状态转移表过程注意：行从底向顶遍历，列从j==i开始遍历，为了解决子串长度>2时，需要用到dp[i+1][j-1]（左下）位置数据
     *
     * 复杂度分析
     *  暴力法：空间复杂度O(1)，时间复杂度O(n^3)
     *  动态规划：空间复杂度O(n^2)，时间复杂度O(n^2)
     */
    string longestPalindrome(string s) {
        if (s.size() < 2) {
            return s;
        }
        
        int start = 0;
        int maxLength = 1;
        
        int row = (int)s.size();
        vector<vector<int>> dp(row, vector<int>(row));
        for (int i = row - 1; i >= 0; i--) {
            for (int j = i; j < row; j++) {
                int length = j - i + 1;
                if (length <=2 && s[i] == s[j]) {
                    dp[i][j] = 1;
                    if (length > maxLength) {
                        start = i;
                        maxLength = length;
                    }
                }
                if (length > 2 && s[i] == s[j] && dp[i+1][j-1] == 1) {
                    dp[i][j] = 1;
                    if (length > maxLength) {
                        start = i;
                        maxLength = length;
                    }
                }
            }
        }
        
        return s.substr(start, maxLength);
    }
};

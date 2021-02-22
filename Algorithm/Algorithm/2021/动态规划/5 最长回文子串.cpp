//
//  5 最长回文子串.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2021/2/22.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        /*
        1. 动态转移表：dp[i][j]表示[s[i] s[j]]是否为回文字符串
        2. 定义状态转移方程：
            2.1 如果[i, j]长度<=2，dp[i][j] = (s[i]==s[j])
            2.2 如果[i, j]长度>2, 当dp[i+1][j-1]是回文串，dp[i][j] = (s[i]==s[j])，否则dp[i][j] = false
         */
        if (s.size() == 0) {
            return s;
        }
        
        vector<vector<bool>> result(s.size());
        for (int i = 0; i < result.size(); i++) {
            result[i].resize(s.size());
        }
        
        int startIndex = 0;
        int len = 1;
        // 从下到上
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            //从左到右
            for (int j = i; j < s.size(); j++) {
                if (j - i <= 1) {
                    if (s[i] == s[j]) {
                        result[i][j] = true;
                        if (j - i + 1 > len) {
                            len = j - i + 1;
                            startIndex = i;
                        }
                    } else {
                        result[i][j] = false;
                    }
                } else {
                    if (result[i+1][j-1] == true && s[i] == s[j]) {
                        result[i][j] = true;
                        if (j - i + 1 > len) {
                            len = j - i + 1;
                            startIndex = i;
                        }
                    } else {
                        result[i][j] = false;
                    }
                }
            }
        }
        
        return s.substr(startIndex, len);
    }
};

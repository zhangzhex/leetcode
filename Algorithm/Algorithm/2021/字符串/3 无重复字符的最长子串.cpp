//
//  3 无重复字符的最长子串.cpp
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
    int lengthOfLongestSubstring(string s) {
        /*
        1. 从i=1开始遍历数组, Pi表示s[i]字符上一次出现的位置
        2. li表示以s[i-1]结尾的字符串的起始位置
        3. 比较li <= Pi 则 li = Pi+1
         */
        if (s.length() == 0) {
            return 0;
        }
        vector<int> preIndex(128, -1);
        preIndex[s[0]] = 0;
        int li = 0;
        int len = 1;
        for (int i = 1; i < s.length(); i++) {
            int pi = preIndex[s[i]];
            if (li <= pi) {
                li = pi + 1;
            }
            preIndex[s[i]] = i;
            len = max(len, i - li + 1);
        }
        return len;
    }
};

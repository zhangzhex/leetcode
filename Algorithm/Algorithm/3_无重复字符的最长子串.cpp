//
//  3_无重复字符的最长子串.cpp
//  Algorithm
//
//  Created by zack on 2020/6/17.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     *思路：1、遍历字符串每一个字符
     *2、当前字符结尾的最大子串长度 与 以前一个字符结尾最大子串的起始位置 以及 当前字符上一次出现的位置有关
     *  2.1、如果当前字符上一次出现位置存在且出现位置>=以前一个字符结尾最大子串的起始位置，得到当前字符结尾的最大子串起始位置
     *  2.2、否则当前字符结尾的最大子串起始位置 = 前一个字符结尾最大子串的起始位置
     *3、起始位置确定后，比较最大子串长度
     */
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        
        map<char, int> mapString;
        mapString[s[0]] = 0;
        
        int preStartIndex = 0;
        int maxLength = 1;
        for (int i = 1; i < s.length(); i++) {
            map<char, int>::iterator iter = mapString.find(s[i]);
            if(iter != mapString.end() && iter->second >= preStartIndex) {
                preStartIndex = iter->second + 1;
            }
            mapString[s[i]] = i;
            maxLength = max(maxLength, i - preStartIndex + 1);
        }
        
        return maxLength;
    }
};

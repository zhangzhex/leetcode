//
//  242_有效的字母异位词.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2020/6/11.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     *思路：使用数组数据结构，遍历字符串字符，把字符 - ‘a’作为索引，出现次数作为值
     */
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        vector<int> vec(26);
        for (int i = 0; i < s.length(); i++) {
            vec[(int)(s[i] - 'a')] += 1;
        }
        
        for (int i = 0; i < t.length(); i++) {
            if (--vec[t[i] - 'a'] < 0) {
                return false;
            }
        }
        
        return true;
    }
};

//
//  面试题 01_09_ 字符串轮转.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2020/6/9.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        
        string str = s1+s1;
        if (str.find(s2) == string::npos) {
            return false;
        }
        return true;
    }
};

//
//  面试题 01 09  字符串轮转.cpp
//  Algorithm
//
//  Created by zack on 2021/2/18.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        
        string s = s1.append(s1);
        string::size_type idx = s.find(s2);
        if (idx == string::npos)     return false;
        return true;
    }
};

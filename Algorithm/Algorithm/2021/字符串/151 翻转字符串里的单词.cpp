//
//  151 翻转字符串里的单词.cpp
//  Algorithm
//
//  Created by zack on 2021/2/20.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        /*
        1. 去除多余空格
        2. 反转整个字符串
        3. 再次反转单个单词
         */
        int curr = 0;
        bool space = true; //前一个字符是否为空格，默认yes
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ')  {
                s[curr] = s[i];
                curr++;
                space = false;
            } else if (space == false){
                s[curr] = s[i];
                curr++;
                space = true;
            }
        }
        int len = space == true ? curr-1 : curr;
        
        reverse(s, 0, len);
        
        int preSpace = -1;
        for (int i = 0; i < len; i++) {
            if (s[i] != ' ') {
                continue;
            }
            reverse(s, preSpace+1, i);
            preSpace = i;
        }
        
        reverse(s, preSpace+1, len);
        
        return string(s, 0, len);
    }
    // [l, r)
    void reverse(string s, int l, int r) {
        r--;
        while (l < r) {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l++;
            r++;
        }
    }
};

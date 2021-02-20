//
//  151_翻转字符串里的单词.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2020/6/15.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;


class Solution {
public:
    /**
     *思路：1、去除字符串无效空格(头、尾、中间)，得到有效长度。（空间复杂度O(1)）
     *2、翻转字符串
     *3、翻转每个单词
     */
    string reverseWords(string s) {
        // 去除空格
        int curr = 0;
        bool space = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                s[curr] = s[i];
                curr++;
                space = false;
            } else if (space == false){
                s[curr] = s[i];
                curr++;
                space = true;
            }
        }
        int length = space ? curr - 1 : curr;
        if(length <= 0) return string();
        
        
        // 翻转字符串
        reverseString(s, 0, length);
        
        // 翻转单词
        int left = -1;
        for (int i = 0; i < length; i++) {
            if (s[i] == ' ') {
                reverseString(s, left+1, i);
                left = i;
            }
        }
        reverseString(s, left+1, length);

        string str(s, 0, length);
        return str;
    }
    
    // 左闭右开区间
    void reverseString(string &s, int left, int right) {
        right--;
        
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            
            left++;
            right--;
        }
    }
};

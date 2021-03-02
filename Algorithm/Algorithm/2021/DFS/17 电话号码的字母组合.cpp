//
//  17 电话号码的字母组合.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2021/3/1.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
     string letterStr;
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0) {
            return result;
        }
        
        vector<vector<char>> digitArray = {
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
        };

        dfs(0, result, digits, digitArray);
        return result;
    }
    // i表示层数
    void dfs(int p, vector<string> &result, string &digits, vector<vector<char>> &digitArray) {
        //最后一层就是结果
        if (p == digits.size()) {
            result.push_back(letterStr);
            return;
        }
        
        //遍历每一层所有情况
        char dig = digits[p];
        vector<char> letters = digitArray[dig - '2'];
        for (int i = 0; i < letters.size(); i++) {
            char letter = letters[i];
            if (letterStr.size() < digits.size()) {
                letterStr = letterStr + letter;
            } else {
                letterStr[p] = letter;
            }
            dfs(p+1, result, digits, digitArray);
        }

    }
};

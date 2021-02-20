//
//  17.cpp
//  Algorithm
//
//  Created by zack on 2020/7/19.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     *思路： 想象递归方法只有一层，简化执行流程
     */
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0) return result;
        
        unordered_map<char, string> table{
        {'0', " "}, {'1',"*"}, {'2', "abc"},
        {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
        {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
        {'9',"wxyz"}};
        dfs(result, 0, digits, "", table);
        return result;
    }
    
    void dfs(vector<string> &result, int depth, string &digits, string combination, unordered_map<char, string> &table) {
        // 执行完最后一层后，字母组合产生
        if (combination.size() == digits.size()) {
            result.push_back(combination);
            return;
        }
        
        // 找当前层的所有字符
        string letters = table[digits[depth]];
        for (char letter : letters) {
            // 字符拼接
            combination += letter;
            // 进入下一层
            dfs(result, depth+1, digits, combination, table);
            // 一次循环结束，遍历下个字符
            combination.pop_back();
        }
    }
};


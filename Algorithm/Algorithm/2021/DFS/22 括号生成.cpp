//
//  22 括号生成.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2021/3/3.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //层数 = n*2
        vector<string> result;
        if (n == 0) {
            return result;
        }
        
        string st(n*2, ' ');
        dfs(0, n, result, st, n, n);
        return result;
    }
    
    void dfs(int depth, int n, vector<string> &result, string &parenthesis, int leftRemain, int rightReamin) {
        // 最后一层为结果
        if (depth == n<<1) {
            string str(parenthesis);
            result.push_back(string(str));
        }
        
        // 遍历每层所有情况，每层最多两种可能，既选（ 或者 ）
        if (leftRemain > 0) {
            parenthesis[depth] = '(';
            dfs(depth+1, n, result, parenthesis, leftRemain-1, rightReamin);
        }
        
        if (rightReamin > 0 && rightReamin != leftRemain) {
            parenthesis[depth] = ')';
            dfs(depth+1, n, result, parenthesis, leftRemain, rightReamin-1);
        }
    }
};

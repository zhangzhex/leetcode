//
//  62_不同路径.cpp
//  Algorithm
//
//  Created by zack on 2020/6/28.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m==0 || n==0) return 0;
        if (m==1 && n==1) return 1;
        
        vector<vector<int>> value(m);
        for (int i = 0; i < m; i++) {
            value[i].resize(n);
        }
        //初始化第0列
        value[0][0] = 0;
        for (int i = 1; i < m; i++) {
            value[i][0] = 1;
        }
        //初始化第0行
        for (int i = 1; i < n; i++) {
            value[0][i] = 1;
        }
        //value[i][j]表示走到该位置的总路径数
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                value[i][j] = value[i-1][j] + value[i][j-1];
            }
        }
        return value[m-1][n-1];
    }
};

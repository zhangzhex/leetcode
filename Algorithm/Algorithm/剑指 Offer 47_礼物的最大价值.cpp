//
//  剑指 Offer 47_礼物的最大价值.cpp
//  Algorithm
//
//  Created by zack on 2020/6/20.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <windows.h>


using namespace std;

class Solution {
public:
    /**
     *思路：1、利用动态规划思想，建立m*n的二维数组，第0行和第0列的每个元素可以得出固定值
     *2、其他位置元素通过求最大值得到，（每次向右或向下移动意味着当前位置g[a][b]的最大值 = Max(g[a-1][b], g[a][b-1]) + v[a][b]
     */
    int maxValue(vector<vector<int>>& grid) {
        uint64_t row = grid.size();
        uint64_t col = grid[0].size();

        vector<vector<int>> value(row);
        for (int i = 0; i < row; i++) {
            value[i].resize(col);
        }

        //初始化第0行
        value[0][0] = grid[0][0];
        for (int i = 1; i < col; i++) {
            value[0][i] = value[0][i-1] + grid[0][i];
        }
        //初始化第0列
        for (int i = 1; i < row; i++) {
            value[i][0] = value[i-1][0] + grid[i][0];
        }
        
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                value[i][j] = max(value[i-1][j], value[i][j-1]) + grid[i][j];
            }
        }
        
        return value[row-1][col-1];
    }
};

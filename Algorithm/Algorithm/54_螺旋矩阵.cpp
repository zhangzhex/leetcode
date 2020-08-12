//
//  54_螺旋矩阵.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2020/8/12.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     *思路：按圈层遍历，注意特殊边界场景
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() == 0) {
            return result;
        }
        int top = 0;
        int bottom = (int)matrix.size()-1;
        int left = 0;
        int right = (int)matrix[0].size()-1;
        
        while (top >= bottom && left <= right) {
            // 上行
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;
            if (top > bottom) break;
            
            // 右列
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
            if (right < left) break;
            
            // 下行
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
            if (top > bottom) break;
            
            // 左列
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        return result;
    }
};

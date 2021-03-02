//
//  46 全排列.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2021/3/2.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
    vector<int> flag;
    vector<int> arr;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0) {
            return result;
        }
        for (int i = 0; i < nums.size(); i++) {
            flag.push_back(0);
            arr.push_back(0);
        }
        dfs(0, nums, result);
        return result;
    }
    void dfs(int i, vector<int>& nums, vector<vector<int>> &result) {
        // 最后一层为结果
        if (i == nums.size()) {
            vector<int> vec(arr);
            result.push_back(vec);
            return;
        }
        
        //遍历当前所有情况
        for (int j = 0; j < nums.size(); j++) {
            // 标记使用过
            if (flag[j] == 1) continue;
            arr[i] = nums[j];
            flag[j] = 1;
            
            dfs(i+1, nums, result);
            flag[j] = 0;//返回上一层恢复标记位
        }
    }
};

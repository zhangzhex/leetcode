
//
//  46_全排列.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2020/7/21.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> combination;
        dfs(result, 0, used, combination, nums);
        return result;
    }

    void dfs(vector<vector<int>> &result, int depth, vector<bool> &used, vector<int> combination, vector<int>& nums) {
        // 执行完最后一层后，数字组合产生
        if (combination.size() == nums.size()) {
            result.push_back(combination);
            return;
        }
        
        // 找当前层的所有数字
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            combination.push_back(nums[i]);
            
            dfs(result, depth+1, used, combination, nums);
            
            used[i] = false;
            combination.pop_back();
        }
    }
};

//
//  47_全排列 II.cpp
//  Algorithm
//
//  Created by zack on 2020/7/24.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        dfs(nums, 0, result);
        return result;
    }
    
    void dfs(vector<int>& nums, int depth, vector<vector<int>> &result) {
        // 最后一层
        if (depth == nums.size() - 1) {
            vector<int> v(nums);
            result.push_back(v);
            return;
        }
        
        // 根据当前层数做交换
        for (int i = depth; i < nums.size(); i++) {
            // 检查重复，保证同一个数字在depth位置只出现一次，做到了提前剪枝
            // 因为depth位置多次出现相同数字，depth后面的数字相同，最后排列的结果重复
            if (isRepeat(nums, depth, i)) continue;
            swap(nums, depth, i);
            dfs(nums, depth+1, result);
            // 返回上一层，恢复位置
            swap(nums, depth, i);
        }
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    bool isRepeat(vector<int>& nums, int depth, int j) {
        for (int i = depth; i < j; i++) {
            if (nums[i] == nums[j]) return true;
        }
        return false;
    }
};


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
    /**
     *思路：通过数组本身的元素位置交换
     *规则：1. 第0层，index=0元素与index=[0, size-1]交换
     *      2. 第1层，index=1元素与index=[1, size-1]交换
     *        3. ...
     *          4. 第size-1层，元素与自身交换
     */
    vector<vector<int>> permute(vector<int>& nums) {
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
    
    /*  通过数组标记每层数据可选的值
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
     */
};

//
//  15_三数之和.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2020/7/29.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     *思路：遍历nums数组 nums[i]，左右两个索引指向左右两边，当三数和>0，r--；当三数和<0，l--；每次移动注意去重
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        
        //排序
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int l = i+1;
            int r = (int)nums.size()-1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] == 0) {
                    vector<int> vec{nums[i], nums[l], nums[r]};
                    result.push_back(vec);
                    
                    while (l < r && nums[l] == nums[l+1]) l++;
                    while (l < r && nums[r] == nums[r-1]) r--;
                    l++;
                    r--;
                } else if(nums[i] + nums[l] + nums[r] > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return result;
    }
};

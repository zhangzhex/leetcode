//
//  15 三数之和.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2021/3/14.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }
        
        sort(nums.begin(), nums.end());
        
        int maxIndex = (int)nums.size()-3;
        for (int i = 0; i <= maxIndex; i++) {
            if (i > 0 && nums[i-1] == nums[i]) {
                continue;
            }
            
            int l = i+1;
            int r = (int)nums.size()-1;
            int remain = -nums[i];
            while (l < r) {
                if (nums[l]+nums[r] == remain) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    while(l<r && nums[l]==nums[l+1])l++;
                    while(l<r && nums[r]==nums[r-1])r--;

                    l++;
                    r--;
                } else if ((nums[l]+nums[r]) > remain) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        
        return result;
    }
};

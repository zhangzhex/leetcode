//
//  main.cpp
//  Algorithm
//
//  Created by zack on 2020/4/11.
//  Copyright © 2020 zack. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
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
            if (i >0 && nums[i-1] == nums[i]) {
                continue;
            }
            
            int l = i+1;
            int r = (int)nums.size()-1;
            int remain = -nums[i];
            while (l < r) {
                if (nums[l]+nums[r] == remain) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                } else if (nums[l]+nums[r] > remain) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        
        return result;
    }
};


int main(int argc, const char * argv[]) {
 
    Solution sol;
    vector<int> vec = {0, 0, 0 ,0};
    sol.threeSum(vec);

    
    return 0;
}

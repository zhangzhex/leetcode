//
//  1_两数之和.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2020/7/27.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> m;
        
        for (int i = 0; i < nums.size(); i++) {
            int dif = target - nums[i];
//            if (dif < 0) continue;
            map<int, int>::iterator iter = m.find(dif);
            if (iter != m.end()) {
                result.push_back(m[dif]);
                result.push_back(i);
                break;
            } else {
                m[dif] = i;
            }
        }
        
        return result;
    }
};

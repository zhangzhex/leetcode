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
        if (i == nums.size()) {
            vector<int> vec(arr);
            result.push_back(vec);
            return;
        }
        
        for (int j = 0; j < nums.size(); j++) {
            if (flag[j] == 1) continue;
            arr[i] = nums[j];
            flag[j] = 1;
            
            dfs(i+1, nums, result);
            flag[j] = 0;
        }
    }
};

int main(int argc, const char * argv[]) {
 
    vector<int> arr;
    

    
    Solution solu;
    vector<int> a{1, 2};
    solu.permute(a);
    
    return 0;
}

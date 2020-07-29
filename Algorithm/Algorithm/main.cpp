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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
                    m[nums[i]] = i;
                }
            }
            
            return result;
        }
};





int main(int argc, const char * argv[]) {
    // insert code here...

    int a = -4 >> 1;
    
    Solution solu;
    vector<int> v = {2, 7, 11, 15};
    solu.twoSum(v, 9);
          
//        cout <<"value="<< a << endl;
    return 0;
}

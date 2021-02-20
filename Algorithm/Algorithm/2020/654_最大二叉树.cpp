//
//  654_最大二叉树.cpp
//  Algorithm
//
//  Created by zack on 2020/5/26.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return findRoot(nums, 0, (int)nums.size());
    }
    
    TreeNode *findRoot(vector<int>& nums, int leftIndex, int rightIndex){
        if (leftIndex >= rightIndex) {
            return NULL;
        }
        
        int maxIndex = leftIndex;
        for (int i = leftIndex + 1; i < rightIndex; i++) {
            if (nums[maxIndex] < nums[i]) {
                maxIndex = i;
            }
        }

        TreeNode *root = new TreeNode(nums[maxIndex]);
        root->left = findRoot(nums, leftIndex, maxIndex);
        root->right = findRoot(nums, maxIndex+1, rightIndex);
        return root;
    }
};

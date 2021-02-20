//
//  654 最大二叉树.cpp
//  Algorithm
//
//  Created by zack on 2021/2/15.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return findRoot(nums, 0, (int)nums.size());
    }
    
    TreeNode *findRoot(vector<int>& nums, int l, int r) {
        if (l == r) return nullptr;
        
        int maxIndex = l;
        for (int i = l+1; i < r; i++) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
        
        TreeNode *root = new TreeNode(nums[maxIndex]);
        root->left = findRoot(nums, l, maxIndex);
        root->right = findRoot(nums, maxIndex+1, r);
        return root;
    }
    
};

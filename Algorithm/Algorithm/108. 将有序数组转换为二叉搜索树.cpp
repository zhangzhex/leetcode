//
//  108. 将有序数组转换为二叉搜索树 108.cpp
//  Algorithm
//
//  Created by zack on 2020/7/19.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return creatBST(nums, 0, (int)nums.size()-1);
    }

    TreeNode *creatBST(vector<int> &nums, int l, int r) {
        if  (l > r) return NULL;
        int middle = l + ((r-l)>>1);
        TreeNode *root = new TreeNode(nums[middle]);
        root->left = creatBST(nums, l, middle-1);
        root->right = creatBST(nums, middle+1, r);
        return root;
    }
};

//
//  230_二叉搜索树中第K小的元素.cpp
//  Algorithm
//
//  Created by zack on 2020/7/19.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>

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
    int current;
    int value;
    int kthSmallest(TreeNode* root, int k) {
        current = 0;
        inorderTraversal(root, k);
        return value;
    }
    
    void inorderTraversal(TreeNode* root, int k) {
        if (root == NULL || current == k) {
            return ;
        }
        inorderTraversal(root->left, k);
        current++;
        if (current == k) {
            value = root->val;
        }
        inorderTraversal(root->right, k);
    }
};

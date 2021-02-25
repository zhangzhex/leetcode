//
//  99 恢复二叉搜索树.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2021/2/25.
//  Copyright © 2021 zack. All rights reserved.
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
    
    TreeNode *pre;
    TreeNode *first;
    TreeNode *second;
public:
    void recoverTree(TreeNode* root) {
        /*
        1. 二叉搜索树中序遍历，应当是升序的顺序
        2. 如果存在逆序，则说明需要恢复
         */
        inorderTree(root);
        
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    
    void inorderTree(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        inorderTree(root->left);
        
        if (pre != nullptr && pre->val > root->val) {
            second = root;
            if (first != nullptr) return;
            first = pre;
        }
        
        pre = root;
        
        inorderTree(root->right);
    }
};

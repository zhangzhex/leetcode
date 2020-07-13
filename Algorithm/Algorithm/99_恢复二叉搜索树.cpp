
//
//  99_恢复二叉搜索树.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2020/7/13.
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
    TreeNode *pre;
    TreeNode *first;
    TreeNode *second;
    
    void recoverTree(TreeNode* root) {
        pre = first = second = NULL;
        inOrderTreee(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    
    void inOrderTreee(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inOrderTreee(root->left);
        
        if (pre != NULL && pre->val > root->val) {
            second = root;
            
            if (first != NULL) return;
            first = pre;
        }
        pre = root;
        
        inOrderTreee(root->right);
    }
};

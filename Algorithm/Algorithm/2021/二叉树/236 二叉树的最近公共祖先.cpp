//
//  236 二叉树的最近公共祖先.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2021/2/24.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        1. 后续遍历思想，先比遍历左子树，在遍历右子树
        2. 终止条件是root == p || root == q || root == null
        */
        if (root == nullptr || root == p || root == q)  {
            return root;
        }
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr) {
            return root;
        }
        if (left != nullptr) {
            return left;
        } else {
            return right;
        }
    }
};
